/*
 * linux/arch/sh/mm/extable.c
 *  Taken from:
 *   linux/arch/i386/mm/extable.c
 */

#include <linux/config.h>
#include <linux/module.h>
#include <linux/kgdb.h>
#include <asm/uaccess.h>

int fixup_exception(struct pt_regs *regs)
{
	const struct exception_table_entry *fixup;

	fixup = search_exception_tables(regs->pc);
	if (fixup) {
		regs->pc = fixup->fixup;
		return 1;
	}
#ifdef CONFIG_KGDB
	if (atomic_read(&debugger_active) && kgdb_may_fault)
		/* Restore our previous state. */
		kgdb_fault_longjmp(kgdb_fault_jmp_regs);
		/* Never reached. */
#endif

	return 0;
}
