#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#define LICENSE_TYPE "GPL"
#define AUTHOR "victor"
#define DESCRIPTION "Task01, hello world"

#define MESSAGE_HELLO "Hello World!"
#define MESSAGE_CLEAN "Good bye, world"

MODULE_LICENSE(LICENSE_TYPE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);

//NOTE: it is important to include the parameters in the prototypes

/*
 * After boot the system, the kernel will call this module
 */
static int __init printHelloWorld(void){
  //for printing messages is better using printk than printf
  //printk is used in kernel space and printf is used in user space
  printk(KERN_INFO MESSAGE_HELLO);
  return 0;
}

/*
 * When cleaning the loadable modules is important to include
 * the function __exit.
 */
static void __exit cleanHelloWorld(void){
  printk(KERN_INFO MESSAGE_CLEAN);
}

/*
 * Call the modules
 */
module_init(printHelloWorld);
module_exit(cleanHelloWorld);

