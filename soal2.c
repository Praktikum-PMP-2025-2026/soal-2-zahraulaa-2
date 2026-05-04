// EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
// Modul               : 4
// Hari dan Tanggal    : Senin, 4 Mei 2026
// Nama (NIM)          : Zahra Aulia (13224007)
// Nama File           : soal2.c
// Deskripsi           : Program menggabungkan dua buah linked list yang sudah terururt kemudia mengurutkannya lagi

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* new_Node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* mergeTwoLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    struct Node temp;
    struct Node* tail = &temp;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;
    return temp.next;
}

void display(struct Node* head) {
    if (head == NULL) { 
        printf("MERGED EMPTY");
    } else {
    struct Node *temp = head;
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    }
}

int main() {
    struct Node *list1, *list2;
    int n, m;
    scanf("%d %d %d %d",n, &list1, m, &list2);

	struct Node* result = mergeTwoLists(list1, list2);
    display(result);

    return 0;
}

/* REFERENSI
1. https://www.w3resource.com/c-programming-exercises/linked_list/c-linked_list-exercise-35.php
2. https://stackoverflow.com/questions/2348374/merging-two-sorted-linked-lists
3. https://www.youtube.com/watch?v=zzk9BQro7bA
*/
