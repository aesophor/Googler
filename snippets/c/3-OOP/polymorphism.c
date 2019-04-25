#include <stdio.h>
#include <stdlib.h>

typedef struct Base Base;


/* Interface aka vtable */
typedef struct base_vtable
{
    void (*dance)(Base*);
    void (*jump)(Base*);
} vtable_t;


/* class Base and its methods */
typedef struct Base
{
    vtable_t* vtable;
    /* Base class members */
} Base;

void base_dance(Base* self)
{
    self->vtable->dance(self);
}

void base_jump(Base* self)
{
    self->vtable->jump(self);
}



/* class Derived1 and its methods */
typedef struct Derived1
{
    Base super;
    /* Derived1 class members */
} Derived1;


void derived1_dance(Derived1* self)
{
    printf("Derived1 object danced\n");
}

void derived1_jump(Derived1* self)
{
    printf("Derived1 object jumped\n");
}



/* class Derived2 and its methods */
typedef struct Derived2
{
    Base super;
    /* Derived2 class members */
} Derived2;

void derived2_dance(Derived2* self)
{
    printf("Derived2 object danced\n");
}

void derived2_jump(Derived2* self)
{
    printf("Derived2 object jumped\n");
}



/* Setup global vtable for Base and Derived */
vtable_t vtable_Derived1 = { derived1_dance, derived1_jump };
vtable_t vtable_Derived2 = { derived2_dance, derived2_jump };

void derived1_init(Derived1* self)
{
    self->super.vtable = &vtable_Derived1;
}

void derived2_init(Derived2* self)
{
    self->super.vtable = &vtable_Derived2;
}

int main(int argc, char** args)
{
    Base* base = (Base*)malloc(sizeof(Base));

    Derived1* d1 = (Derived1*)malloc(sizeof(Derived1));
    d1->super.vtable = &vtable_Derived1;
    Derived2* d2 = (Derived2*)malloc(sizeof(Derived2));
    d2->super.vtable = &vtable_Derived2;

    printf("d1 addr: %p\n", d1);
    printf("d2 addr: %p\n", d2);

    base_dance(d1);
    base_dance(d2);

    base_jump(d1);
    base_jump(d2);
}
