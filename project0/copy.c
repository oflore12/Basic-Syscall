#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE3(memory_copy, unsigned char __user *, to, unsigned char __user *, from, int, size){

	//check if access is okay first 
	int rc_from = access_ok(from,size);
	int rc_to = access_ok(to, size);

	if(rc_from != 1 && rc_to != 1){
		printk("error in access from user space or kernel space");
		return -EFAULT;
	}
	int space = -1;
	if(from!='\0'){
		space = copy_from_user(to, from, size);
	}
	else{
		space = copy_to_user(to, from, size);
	}

	if(space != 0){
		printk("error in access from user space or kernel space");
                return -EFAULT;
	}else{
	return 0;
	}
	printk("something else went wrong");
	return -1;
}
