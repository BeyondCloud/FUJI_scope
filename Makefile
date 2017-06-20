PROJECT = FUJIscope
######################################
# building variables
######################################
HIDE_WARNING = 1
# debug build?
DEBUG = 1
# optimization
OPT = -O3

#######################################
# pathes
#######################################
# Build path
OUTDIR =  build
TOOL_DIR = tool

BIN_IMAGE = $(OUTDIR)/$(PROJECT).bin
EXECUTABLE = $(OUTDIR)/$(PROJECT).elf

MAP_FILE = $(OUTDIR)/$(PROJECT).map

SRC_DIR  =	 Drivers/STM32F4xx_HAL_Driver/Src \
			 Src/ui \
			 Src 
			 

INC_DIR = 	 Drivers/CMSIS/Device/ST/STM32F4xx/Include \
			 Drivers/CMSIS/Include \
		 	 Drivers/STM32F4xx_HAL_Driver/Inc \
			 Drivers/STM32F4xx_HAL_Driver/Inc/Legacy \
			 Inc/images \
		 	 Inc/ui \
			 Inc
######################################
# source
######################################
C_SOURCES += $(wildcard $(addsuffix /*.c,$(SRC_DIR)))

ASM_SOURCES = startup/startup_stm32f407xx.s

#######################################
# binaries
#######################################
CC = arm-none-eabi-gcc
AS = arm-none-eabi-gcc -x assembler-with-cpp
CP = arm-none-eabi-objcopy
AR = arm-none-eabi-ar
SZ = arm-none-eabi-size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

#######################################
# CFLAGS
#######################################
# macros for gcc
C_DEFS = -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F407xx
# includes for gcc
INCLUDES += $(addprefix -I,$(INC_DIR))

# compile gcc flags
CFLAGS = -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard $(C_DEFS) $(INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections
ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif
ifeq ($(HIDE_WARNING), 1)
CFLAGS += -w
endif

# Generate dependency information
CFLAGS += -std=c99  -MD -MP -MF .dep/$(@F).d
#Floating point 
CFLAGS +=-DARM_MATH_CM4  -D__FPU_PRESENT
# Optimizations
CFLAGS += -O3 -ffast-math \
		  -ffunction-sections -fdata-sections \
		  -fno-common \
		  --param max-inline-insns-single=1000 \
#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F407VGTx_FLASH.ld
# libraries
#LIBS is optional , you can remove it
LIBS = -lc -lm -lnosys
LDFLAGS = -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -specs=nano.specs
LDFLAGS+= -T$(TOOL_DIR)/STM32F407VGTx_FLASH.ld $(LIBS)
LDFLAGS +=-Wl,-Map=$(MAP_FILE),--cref -Wl,--gc-sections


MAKDIR = mk
MAK = $(wildcard $(MAKDIR)/*.mk)

# default action: build all
all: $(OUTDIR)/$(PROJECT).elf $(OUTDIR)/$(PROJECT).hex $(BIN_IMAGE)

include $(MAK)
#######################################
# build the application
#######################################
# list of ObjectS


OBJS = $(addprefix $(OUTDIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program OBJS
OBJS += $(addprefix $(OUTDIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
OBJS += $(RTOSOBJS) $(UGFXOBJS) $(FATOBJS)
vpath %.s $(sort $(dir $(ASM_SOURCES)))
$(OUTDIR)/%.o: %.c Makefile | $(OUTDIR)
	@echo "   MAIN  |   CC    "$@
	@$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(OUTDIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(OUTDIR)/%.o: %.s Makefile | $(OUTDIR)
	@echo "   MAIN  |   AS    "$@
	@$(AS) -c $(CFLAGS) $< -o $@

$(OUTDIR)/$(PROJECT).elf: $(OBJS)   Makefile
	@echo "   ALL   |   LD    "$@
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@$(SZ) $@

$(OUTDIR)/%.hex: $(OUTDIR)/%.elf | $(OUTDIR)
	$(HEX) $< $@

$(OUTDIR)/%.bin: $(OUTDIR)/%.elf | $(OUTDIR)
	$(BIN) $< $@

$(OUTDIR):
	mkdir -p $@

#######################################
# clean up
#######################################
clean:
	-rm -fR .dep $(OUTDIR)
# Flash the STM32F4
flash: $(EXECUTABLE)
	st-flash write $(BIN_IMAGE) 0x8000000


#######################################
# dependencies
#######################################
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

.PHONY: clean all

# *** EOF ***
