#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <list.h>

void test_make_and_free_list(void) {
    struct list *lst = make_list();
    assert(lst != NULL);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);
    assert(lst->length == 0);

    assert(free_list(NULL) == LIST_NULL_POINTER);

    int res = free_list(lst);
    assert(res == 0);

    printf("test_make_and_free_list passed!\n");
}

void test_list_push(void) {
    struct list *lst = make_list();
    assert(lst != NULL);

    int a = 10, b = 20, c = 30;

    assert(list_push(lst, &a) == 1);
    assert(lst->length == 1);
    assert(lst->head->value == &a);
    assert(lst->tail->value == &a);
    assert(lst->head->prev == NULL);
    assert(lst->head->next == NULL);

    assert(list_push(lst, &b) == 2);
    assert(lst->length == 2);
    assert(lst->head->value == &a);
    assert(lst->tail->value == &b);
    assert(lst->head->next == lst->tail);
    assert(lst->tail->prev == lst->head);

    assert(list_push(lst, &c) == 3);
    assert(lst->length == 3);
    assert(lst->head->value == &a);
    assert(lst->tail->value == &c);
    assert(lst->tail->prev->value == &b);

    free_list(lst);
    printf("test_list_push passed!\n");
}

void test_list_unshift(void) {
    struct list *lst = make_list();
    assert(lst != NULL);

    int a = 10, b = 20, c = 30;

    assert(list_unshift(lst, &a) == 1);
    assert(lst->length == 1);
    assert(lst->head->value == &a);
    assert(lst->tail->value == &a);

    assert(list_unshift(lst, &b) == 2);
    assert(lst->length == 2);
    assert(lst->head->value == &b);
    assert(lst->tail->value == &a);
    assert(lst->head->next == lst->tail);
    assert(lst->tail->prev == lst->head);

    assert(list_unshift(lst, &c) == 3);
    assert(lst->length == 3);
    assert(lst->head->value == &c);
    assert(lst->head->next->value == &b);
    assert(lst->head->next->prev == lst->head);

    free_list(lst);
    printf("test_list_unshift passed!\n");
}

int main(void) {
    printf("=== Running libds list unit tests ===\n");
    test_make_and_free_list();
    test_list_push();
    test_list_unshift();
    printf("=== All list tests passed successfully! ===\n");
    return 0;
}