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

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* mergelists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    struct Node temp;
    struct Node* tail = &temp;
    temp.next = NULL;

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

    if (head1) tail->next = head1;
    if (head2) tail->next = head2;

    return temp.next;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("MERGED EMPTY");
    } else {
        struct Node *temp = head;
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

struct Node* createlist(int n) {
    if (n <= 0) return NULL;
    int x;
    scanf("%d", &x);
    struct Node* head = newNode(x);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        temp->next = newNode(x);
        temp = temp->next;
    }
    return head;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Node* list1 = createlist(n);
    struct Node* list2 = createlist(m);
    struct Node* result = mergelists(list1, list2);
    display(result);
    return 0;
}
