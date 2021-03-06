//
//  main.cpp
//  LinkQueue
//
//  Created by 罗璞 on 2017/11/7.
//  Copyright © 2017年 Rbtoooooooooo. All rights reserved.
//

//链队列
#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;


/**
 初始化

 @param q 队列的名称
 */
void initLinkQueue(LinkQueue &q) {
    q.front = q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    q.front->next = NULL;
    q.front->data = 0;
    printf("初始化完成！\n");
}


/**
 判空

 @param q 队列的名称
 @return 空返回true，非空返回false；
 */
bool isEmpty(LinkQueue &q) {
    if (q.rear == q.front) {
        printf("队空\n");
        return true;
    }
    return false;
}

/**
 入队

 @param q 队列的名称
 @param e 入队的元素
 */
void enQueue(LinkQueue &q, int e) {
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
    q.front->data++;
}

/**
 出队

 @param q 队列的名称
 @param e 通过参数返回出队的元素
 @return 出队是否成功
 */
bool deQueue(LinkQueue &q, int &e) {
    if (isEmpty(q)) {
        return false;
    }
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s = q.front->next;
    e = s->data;
    q.front->next = s->next;
    q.front->data--;
    if (s == q.rear) {
        q.rear = q.front;
    }
    
    return true;
}

bool print(LinkQueue q) {
    if (isEmpty(q)) {
        return false;
    }
    printf("链队中共有%d个元素！\n", q.front->data);
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s = q.front->next;
    while (s!=NULL) {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...

    LinkQueue q;
    int e;
    initLinkQueue(q);
    enQueue(q, 1);
    enQueue(q, 99);
    print(q);
    deQueue(q, e);
    print(q);
    deQueue(q, e);
    print(q);
    deQueue(q, e);
    
    
//   小实验
//    LinkNode *a, *b, *c;
//    a=b=(LinkNode*)malloc(sizeof(LinkNode));  // a,b指向同一片空间，并未开辟两片空间
//    c=(LinkNode*)malloc(sizeof(LinkNode));    // c指向另一篇空间
//    a->data = 10;                             // a,b指向的这篇空间的data等于10，即b->data也等于10
//    c->data = 12;                             // c指向的这片空间的data等于12
//    b = c;                                    // 改变b的指向，这时b->data等于c->data,但是a->data并未改
                                                // 变，还是等于10
//    printf("%d, %d\n", a->data, b->data);     // 检验
    // 需要注意的是a->data=10改变的b->data,但是b=c却并未改变a->data;
    
    return 0;
}















