EXTRA_CFLAGS := -Werror

obj-$(CONFIG_OPROFILE) += oprofile.o

DRIVER_OBJS = $(addprefix ../../../drivers/oprofile/, \
		oprof.o cpu_buffer.o buffer_sync.o \
		event_buffer.o oprofile_files.o \
		oprofilefs.o oprofile_stats.o \
		timer_int.o )

oprofile-y				:= $(DRIVER_OBJS) common.o mips_backtrace.o

#oprofile-$(CONFIG_CPU_MIPS32_R1)		+= op_model_mipsxx.o
#oprofile-$(CONFIG_CPU_MIPS64_R1)		+= op_model_mipsxx.o
oprofile-$(CONFIG_CPU_RM9000)			+= op_model_rm9000.o
oprofile-$(CONFIG_MIPS_BCM7038)			+= op_model_brcm7038.o
oprofile-$(CONFIG_MIPS_BCM7318)			+= op_model_brcm3300.o
oprofile-$(CONFIG_MIPS_BCM3560)			+= op_model_brcm3300.o
oprofile-$(CONFIG_MIPS_BCM7401)			+= op_model_brcm3300.o
oprofile-$(CONFIG_MIPS_BCM7403)			+= op_model_brcm3300.o
oprofile-$(CONFIG_MIPS_BCM7452)			+= op_model_brcm3300.o
oprofile-$(CONFIG_MIPS_BCM7118)			+= op_model_brcm3300.o
oprofile-$(CONFIG_MIPS_BCM7400)			+= op_model_brcm4350.o
oprofile-$(CONFIG_MIPS_BCM7440A0)              += op_model_brcm4350.o
