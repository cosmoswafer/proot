/* This file is automatically generated from the documentation. EDIT AT YOUR OWN RISK. */

#ifndef CLI_H
#define CLI_H

#include <stddef.h>
#include "build.h"

struct argument {
	const char *name;
	char separator;
	const char *value;
};

typedef void (*option_handler_t)(char *value);

struct option {
	const char *class;
	option_handler_t handler;
	const char *description;
	const char *detail;
	struct argument arguments[5];
};

#ifndef VERSION
#define VERSION "2.0.1"
#endif
static const char *version = VERSION;
static const char *subtitle = "chroot, mount --bind, and binfmt_misc without privilege/setup";
static const char *synopsis = "proot [option] ... [command]";
static const char *colophon = "Visit http://proot.me for help, bug reports, suggestions, patchs, ...\n\
Copyright (C) 2012 STMicroelectronics, licensed under GPL v2 or later.";

static char *recommended_bindings[] = {
	"/etc/host.conf",
	"/etc/hosts",
	"/etc/hosts.equiv",
	"/etc/mtab",
	"/etc/netgroup",
	"/etc/networks",
	"/etc/passwd",
	"/etc/group",
	"/etc/nsswitch.conf",
	"/etc/resolv.conf",
	"/etc/localtime",
	"/dev/",
	"/sys/",
	"/proc/",
	"/tmp/",
	"$HOME",
	NULL,
};

static void handle_option_r(char *value);
static void handle_option_b(char *value);
static void handle_option_q(char *value);
static void handle_option_w(char *value);
static void handle_option_u(char *value);
static void handle_option_k(char *value);
static void handle_option_0(char *value);
static void handle_option_v(char *value);
static void handle_option_V(char *value);
static void handle_option_h(char *value);
static void handle_option_B(char *value);
static void handle_option_Q(char *value);
static void handle_option_W(char *value);

static struct option options[] = {
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-r", .separator = ' ', .value = "path" },
		{ .name = "--rootfs", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_r,
	  .description = "Use *path* as the new guest root file-system, default is /.",
	  .detail = "\tThe specified path typically contains a Linux distribution where\n\
\tall new programs will be confined.  The default rootfs is /\n\
\twhen none is specified, this makes sense when the bind mechanism\n\
\tis used to relocate host files and directories, see the -b\n\
\toption and the Examples section for details.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-b", .separator = ' ', .value = "path" },
		{ .name = "--bind", .separator = '=', .value = "path" },
		{ .name = "-m", .separator = ' ', .value = "path" },
		{ .name = "--mount", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_b,
	  .description = "Make the content of *path* accessible in the guest rootfs.",
	  .detail = "\tThis option makes any file or directory of the host rootfs\n\
\taccessible in the confined environment just as if it were part of\n\
\tthe guest rootfs.  By default the host path is bound to the same\n\
\tpath in the guest rootfs but users can specify any other location\n\
\twith the syntax: -b *host_path*:*guest_location*. Such\n\
\tbindings are said \"asymmetric\".",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-q", .separator = ' ', .value = "command" },
		{ .name = "--qemu", .separator = '=', .value = "command" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_q,
	  .description = "Execute guest programs through QEMU as specified by *command*.",
	  .detail = "\tEach time a guest program is going to be executed, PRoot inserts\n\
\tthe QEMU user-mode command in front of the initial request.\n\
\tThat way, guest programs actually run on a virtual guest CPU\n\
\temulated by QEMU user-mode.  The native execution of host programs\n\
\tis still effective and the whole host rootfs is bound to\n\
\t/host-rootfs in the guest environment.\n\
\t\n\
\tThis option is automatically enabled by the -Q option.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-w", .separator = ' ', .value = "path" },
		{ .name = "--pwd", .separator = '=', .value = "path" },
		{ .name = "--cwd", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_w,
	  .description = "Set the initial working directory to *path*, default is /.",
	  .detail = "\tSome programs expect to be launched from a given directory but do\n\
\tnot perform any chdir by themselves, the most common example\n\
\tis ./configure scripts.  This option avoids the need for\n\
\trunning a shell and then entering the directory manually.\n\
\t\n\
\tSee the -W option.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-u", .separator = '\0', .value = NULL },
		{ .name = "--allow-unknown-syscalls", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_u,
	  .description = "Allow the execution of unknown syscalls.",
	  .detail = "\tPRoot has to know the semantics of a syscall to translate its\n\
\targuments. This is why any syscall that PRoot isn't aware of is\n\
\tblocked.  This option disables this default behavior.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-k", .separator = ' ', .value = "string" },
		{ .name = "--kernel-release", .separator = '=', .value = "string" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_k,
	  .description = "Force syscall uname to report *string* as kernel release.",
	  .detail = "\tTechnically the GNU C library relies on syscalls provided by the\n\
\tkernel that's why it performs a sanity check at each program\n\
\tstart-up to verify whether the current kernel is known to be\n\
\tcompatible.  If users are running a GNU C library that expects a\n\
\tkernel more recent than the one used on their computers, they will\n\
\tget the error \"FATAL: kernel too old\".  This option allows users\n\
\tto cheat this sanity check by faking the release number of the\n\
\tcurrent kernel.  This option should be used with care since it\n\
\tdoes not improve the compatibility.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-0", .separator = '\0', .value = NULL },
		{ .name = "--root-id", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_0,
	  .description = "Force some syscalls to behave as if executed by \"root\".",
	  .detail = "\tSome programs will refuse to work if they are not run with \"root\"\n\
\tprivileges, even if there is no technical reason for that.  This\n\
\tis typically the case with package managers.  This option allows\n\
\tusers to bypass this kind of limitation by faking the user/group\n\
\tidentity, and by faking the success of some operations like\n\
\tchanging the ownership of files, changing the root directory to\n\
\t/, ...  Note that this option is quite limited compared to\n\
\tfakeroot.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-v", .separator = ' ', .value = "value" },
		{ .name = "--verbose", .separator = '=', .value = "value" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_v,
	  .description = "Set the level of debug information to *value*.",
	  .detail = "\tThe higher the integer value is, the more detailled debug\n\
\tinformation is printed to the standard error stream.  A negative\n\
\tvalue makes PRoot quiet except on fatal errors.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-V", .separator = '\0', .value = NULL },
		{ .name = "--version", .separator = '\0', .value = NULL },
		{ .name = "--about", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_V,
	  .description = "Print version, copyright, license and contact, then exit.",
	  .detail = "",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-h", .separator = '\0', .value = NULL },
		{ .name = "--help", .separator = '\0', .value = NULL },
		{ .name = "--usage", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_h,
	  .description = "Print the version and the command-line usage, then exit.",
	  .detail = "",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-B", .separator = '\0', .value = NULL },
		{ .name = "-M", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_B,
	  .description = "Alias: -b for each path of a recommended list",
	  .detail = "\tThere are a couple of bindings that are needed for most guest\n\
\tprograms to behave correctly regarding the configuration part of\n\
\tthe host computer which is not specific to the host Linux\n\
\tdistribution, such as: user/group information, network setup,\n\
\trun-time information, users' files, ... This highly recommended\n\
\toption enables the following bindings:\n\
\t\n\
\t    * /etc/host.conf\n\
\t    * /etc/hosts\n\
\t    * /etc/hosts.equiv\n\
\t    * /etc/mtab\n\
\t    * /etc/netgroup\n\
\t    * /etc/networks\n\
\t    * /etc/passwd\n\
\t    * /etc/group\n\
\t    * /etc/nsswitch.conf\n\
\t    * /etc/resolv.conf\n\
\t    * /etc/localtime\n\
\t    * /dev/\n\
\t    * /sys/\n\
\t    * /proc/\n\
\t    * /tmp/\n\
\t    * $HOME",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-Q", .separator = ' ', .value = "command" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_Q,
	  .description = "Alias: -q *command* -B",
	  .detail = "\tThis option is highly recommended when using QEMU user-mode; it\n\
\tenables all the recommended bindings.",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-W", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_W,
	  .description = "Alias: -b . -w .",
	  .detail = "\tMake the current working directory accessible in the guest rootfs\n\
\tand then use it as the initial working directory.  This option is\n\
\ttypically useful to launch ./configure scripts directly, for\n\
\tinstance.",
	},
};

#endif /* CLI_H */
