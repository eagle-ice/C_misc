/*
 * =====================================================================================
 *
 *       Filename:  macro.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/27/2021 08:00:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#ifndef container_of
/* *
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member. 成员的指针
 * @type:   the type of the container struct this is embedded in. 结构体类型
 * @member: the name of the member within the struct. 结构体成员的名字（和指针对应）
 *
 */

#define container_of(ptr, type, member) ({                  \
        const typeof(((type *)0)->member) * __mptr = (ptr); \
        (type *)((char *)__mptr - offsetof(type, member)); })
#endif

#ifndef max
#define max(x, y) ({                    \
        typeof(x) _max1 = (x);          \
        typeof(y) _max2 = (y);          \
        (void) (&_max1 == &_max2);      \
        _max1 > _max2 ? _max1 : _max2; })
#endif
#ifndef min
#define min(x, y) ({                    \
        typeof(x) _min1 = (x);          \
        typeof(y) _min2 = (y);          \
        (void) (&_min1 == &_min2);      \
        _min1 < _min2 ? _min1 : _min2; })
#endif

#ifndef roundup
#define roundup(x, y) (                   \
        {                                 \
        const typeof(y) __y = y;          \
        (((x) + (__y - 1)) / __y) * __y;  \
        }                                 \
        )
#endif


struct _cont_of_test {
    int a;
    int b;
    int c;
};

void test1(int *c)
{
    struct _cont_of_test *abc = container_of(c, struct _cont_of_test, c);
    printf("test:%p\n", container_of(c, struct _cont_of_test, c));
    printf("a = %d, b = %d, c = %d\n", abc->a, abc->b, abc->c);
}


int main(int argc, char *argv[])
{
    int a = 2;
    int b = 3;
    max(a,b);
    struct _cont_of_test *test = (struct _cont_of_test *)malloc(sizeof(struct _cont_of_test));
    test->a = a;
    test->b = b;
    test->c = a;
    printf("%p\n", test);
    printf("%p\n", container_of(&(test->c), struct _cont_of_test, c));
    test1(&(test->c));
    free(test);
    test = NULL;
    return 0;
}

