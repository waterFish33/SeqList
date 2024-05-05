#include "SeqList.h"

void SeqListInit(SeqList* ps) {
	assert(ps);
	ps->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL) {
		printf("Init malloc fail!\n");
		return;
	}
	ps->capacity = 4;
	ps->size = 0;
}

void SeqListDestroy(SeqList* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListCheck(SeqList* ps) {
	assert(ps);
	if (ps->capacity == ps->size) {
		SLDateType* tmp = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * 2 * ps->capacity);
		if(tmp!=NULL){
			ps->a = tmp;
		}
		else {
			perror("扩容失败");
		}
		ps->capacity = (2 * ps->capacity);
	}
}

void SeqListPrint(SeqList* ps) {
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d  ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x) {
	assert(ps);
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x) {
	assert(ps);
	SeqListInsert(ps, 0, x);
}

void SeqListPopBack(SeqList* ps) {
	assert(ps->size > 0);
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}

void SeqListPopFront(SeqList* ps) {
	assert(ps->size > 0);
	assert(ps);
	SeqListErase(ps, 0);
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i;
		}
	}
	return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDateType x) {
	assert(ps);
	assert(pos<=ps->size);
	assert(ps->size >= 0);
	SeqListCheck(ps);
	for (int i=ps->size;i>pos;i--) {
		ps->a[i] = ps->a[i-1];
	}
	ps->a[pos] = x;
	ps->size++;

}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos) {
	assert(ps);
	assert(pos < ps->size);
	assert(ps->size > 0);
	for (; pos < ps->size; pos++) {
		ps->a[pos] = ps->a[pos + 1];
	}
	ps->size--;
}
