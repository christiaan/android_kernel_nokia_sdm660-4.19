// SPDX-License-Identifier: GPL-2.0
/*
 * Bring-up aid: panic a fixed time after boot.
 *
 * On a phone without a serial console, a boot that hangs or never brings
 * up USB leaves no log unless the system goes down through a warm reset,
 * which keeps the ramoops/pstore region. Boot with ctl_panic_after=<s> on
 * the kernel command line to panic <s> seconds after late init; write 0 to
 * /sys/module/kernel/parameters/ctl_panic_after before then to cancel.
 * Without the parameter this does nothing.
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/workqueue.h>

static int ctl_panic_after;
core_param(ctl_panic_after, ctl_panic_after, int, 0644);

static void ctl_panic_after_fn(struct work_struct *work)
{
	if (ctl_panic_after > 0)
		panic("ctl_panic_after: %d s bring-up timer expired",
		      ctl_panic_after);
}

static DECLARE_DELAYED_WORK(ctl_panic_after_work, ctl_panic_after_fn);

static int __init ctl_panic_after_init(void)
{
	if (ctl_panic_after > 0) {
		pr_warn("ctl_panic_after: will panic in %d s\n",
			ctl_panic_after);
		schedule_delayed_work(&ctl_panic_after_work,
				      msecs_to_jiffies(ctl_panic_after * 1000));
	}
	return 0;
}
late_initcall(ctl_panic_after_init);
