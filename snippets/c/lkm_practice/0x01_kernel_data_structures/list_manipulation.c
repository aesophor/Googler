#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

struct birthday
{
    int day;
    int month;
    int year;
    struct list_head list;
};

int list_manipulation_init(void)
{
    printk(KERN_INFO "Starting List Manipulation Module\n");
    
    // Defines and initializes the variable birthday_list.
    static LIST_HEAD(birthday_list);

    struct birthday *person;

    person = kmalloc(sizeof(*person), GFP_KERNEL);
    person -> day = 2;
    person -> month = 8;
    person -> year = 1995;
    INIT_LIST_HEAD(&person -> list);

    // Add this instance to the end of the linked list.
    list_add_tail(&person -> list, &birthday_list);

    // Traverse through the linked list.
    //list_for_each_entry(person, &birthday_list, list);

    // Remove elements from the list.
    //struct list_head *element = &person -> list;
    //list_del(element);

    // Traverse through the linked list again.
    //list_for_each_entry(person, &birthday_list, list);

    return 0;
}

void list_manipulation_exit(void)
{
    printk(KERN_INFO "Stopped List Manipulation Module\n");
}

module_init(list_manipulation_init);
module_exit(list_manipulation_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("List Manipulation Module");
MODULE_AUTHOR("aesophor");
