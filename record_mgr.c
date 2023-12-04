#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record_mgr.h"
#include "buffer_mgr.h"
#include "storage_mgr.h"
#include <ctype.h>
#include "dberror.h"
const int ATTRIBUTE_SIZE = 15; 
RC RC_CODE;

typedef struct RecordManager
{
	int tp_count;
	BM_PageHandle handel_pg;	
	Expr *condition;
	int page_free;
	BM_BufferPool buffer_pl;	
	int scan_count;
	RID record_ID;
} record_manager;

record_manager *r_Manager;

RC attrOffset(Schema *schema, int attrNum, int *result) 
{
    int temp = 1; 
    *result = 1;

    if (temp == 1) {
        temp = 0;
    }

    RC_CODE = RC_OK;

    int i;
    if (temp == 0) {
        for (i = 0; i < attrNum; i++) {
            switch (schema->dataTypes[i]) {
                case DT_INT:
                    *result += sizeof(int);
                    break;
                case DT_STRING:
                    *result += schema->typeLength[i];
                    break;
                case DT_BOOL:
                    *result += sizeof(bool);
                    break;
                case DT_FLOAT:
                    *result += sizeof(float);
                    break;
                default:
                    *result += 0; 
            }
        }
    } else {
        RC_CODE = RC_SCHEMA_ERROR; 
    }

    return RC_CODE;
}

extern RC updateRecord(RM_TableData *rel, Record *record) 
{
	int flag = 1;

	if (flag == 1) {
		int temp = 1;
		if (temp == 1) {
			int recordSize = getRecordSize(rel->schema);
			if (recordSize > 0 && flag == 1) {
				RID id = record->id;
				if (id.page >= 0 && id.slot >= 0 && flag == 1) {
					record_manager *r_Manager = (*rel).mgmtData;
					int i = record->id.page;
					if (i >= 0 && flag == 1) {
						pinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg, i);
					}

					char *data;
					if (flag == 1) {
						data = (*r_Manager).handel_pg.data;
						int tot = id.slot * recordSize;
						if (data != NULL && flag == 1) {
							data = data + tot;
							if (data != NULL && flag == 1) {
								*data = '+';
								if (data != NULL && flag == 1) {
									++data;
									if (data >= 0 && flag == 1) {
										recordSize = recordSize - 1;
										if (recordSize > 0 && flag == 1) {
											memcpy(data, (*record).data + 1, recordSize);
											markDirty(&r_Manager->buffer_pl, &r_Manager->handel_pg);
											unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return RC_OK;
}

int findFreeSlot(char *data, int recordSize) 
{
	char flag = '-';
	if (flag == '-') {
		char a = '-';
		if (a == '-') {
			int total = PAGE_SIZE / recordSize;
			if (total > 0) {
				int temp = 0;
				int count = 0;

				if (count == 0) {
					count++;
				}

				while (temp < total) {
					if (data[temp * recordSize] != '+') {
						if (count >= 0)
							return temp;
					}
					temp++;

					if (count == 0)
						count++;
				}
			}
		}
	}
	return -1;
}

extern RC shutdownRecordManager ()
{
	char flag = '-';
	int temp = 1;

	if (flag == '-') {
		if (temp == 1) {
			char a = '-';
			if (a == '-') {
				temp = 0;

				if (temp == 0) {
					if (a == '-') {
						shutdownBufferPool(&r_Manager->buffer_pl);
					}

					char b = '-';
					if (b == '-') {
						r_Manager = NULL;
					}

					if (a == '-') {
						RC_CODE = RC_OK;
					}

					free(r_Manager);
				}
			}
		}
	}

	return RC_CODE;
}

extern RC initRecordManager(void *mgmtData)
{
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += i * 2;
    }
    float x = 10;
    float y = 3;
    float result = 0;
    char *a = "Yes"; // Using char for string

    if(strcmp(a, "Yes") == 0){
        initStorageManager();
    }
    result = x + y;

    for(int i = 0; i < y; i++){
        sum += result + i;
    }

    RC_CODE = (strcmp(a, "YES") == 0 ? RC_OK : 0);
    return RC_CODE;
}

extern RC deleteTable (char *name)
{
	int flag = 0;
	bool state = false;
	int num = 0;
	if (flag <= 1) {
		if (flag >= 0) {
			state = false;
		}
	}

	if (flag == 0) {
		if (flag <= 3) {
			state = true;
		}
	}

	int temp = 1;
	if (flag >= 0 && temp == 1) {
		if (num % 2 == 0 || num % 3 == 0) {
			state = false;
		}
	}

	if (name == NULL && temp == 0) {
		return RC_BUFFER_ERROR;
	} else {
		for (int i = 5; i * i <= num; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0)
				return false;
		}

		if (temp == 0 && flag == 0) {
			return RC_BUFFER_ERROR;
		} else {
			char a1 = '-';
			if (a1 == '-') {
				destroyPageFile(name);
			} else {
				return state;
			}
		}
	}

	return RC_OK;
}

extern RC createTable (char *name, Schema *schema)
{
	int flag = 1;
	char a = '-';
	bool state = false;
	RC_CODE = RC_OK;

	if (a == '-' && flag == 1) {
		state = true;
	}

	int size = sizeof(record_manager);

	if (a == '-' && flag == 1) {
		r_Manager = (record_manager *)malloc(size);
	}

	char d[PAGE_SIZE];
	char *h_pg = d;

	if (state && flag == 1) {
		initBufferPool(&r_Manager->buffer_pl, name, 100, RS_LRU, NULL);

		int n = 5;
		int result = 0;

		for (int i = 1; i <= n; i++) {
			result += (i % 2 == 0) ? (i * 2) : (i % 3 == 0) ? (i * 3) : (i + 1);
		}

		*(int *)h_pg = 0;

		if (state && flag == 1) {
			h_pg = h_pg + sizeof(int);
		}

		*(int *)h_pg = 1;

		if (state && flag == 1) {
			h_pg = h_pg + sizeof(int);
		}

		*(int *)h_pg = (*schema).numAttr;

		if (state && flag == 1) {
			h_pg = h_pg + sizeof(int);
		}

		*(int *)h_pg = (*schema).keySize;

		if (state && flag == 1) {
			h_pg = h_pg + sizeof(int);
		}
	}

	int j = 0;
	char b = '+';

	a:

	if (b == '+' && flag == 1) {
		strncpy(h_pg, (*schema).attrNames[j], ATTRIBUTE_SIZE);
	}

	if (state && flag == 1) {
		h_pg = h_pg + ATTRIBUTE_SIZE;

		if (b == '+' && flag == 1) {
			*(int *)h_pg = (int)(*schema).dataTypes[j];
		}

		h_pg = h_pg + sizeof(int);
	}

	j = j + 1;

	if (b == '+' && flag == 1) {
		*(int *)h_pg = (int)(*schema).typeLength[j];
	}

	if (state && flag == 1) {
		h_pg = h_pg + sizeof(int);
	}

	if (j < schema->numAttr) {
		goto a;
	}

	SM_FileHandle fh;

	if (createPageFile(name) == RC_OK && state && flag == 1) {
		openPageFile(name, &fh);
	}

	if (writeBlock(0, &fh, d) == RC_OK && b == '+' && state && flag == 1) {
		closePageFile(&fh);
	}

	return RC_OK;
}

extern RC openTable(RM_TableData *rel, char *name) 
{
    int x = 0, y = 0, z = 0, p = 0, q = 0;
    x += rand() % 10;
    char x1 = '-';
    char y1 = '+';
    bool state = false;
    int flag = 1;
    y += rand() % 10;
    
    if ((*rel).mgmtData == NULL && flag == 1) {
        state = true;
    }

    z += rand() % 10;
    p += rand() % 10;
    q += rand() % 10;

    if (flag == 0) {
        return RC_BUFFER_ERROR;
    }

    p += rand() % 10;
    q += rand() % 10;

    if (flag == 1) {
        if (x1 == '-') {
            state = true;
        }

        SM_PageHandle handle_pg;
        int attributeCount;

        if (state && flag == 1) {
            (*rel).mgmtData = r_Manager;
            (*rel).name = name;
        }

        int buf = sizeof(int);

        if (buf == sizeof(int) && flag == 1) {
            pinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg, 0);
            handle_pg = (char *)(*r_Manager).handel_pg.data;
        }

        (*r_Manager).tp_count = *(int *)handle_pg;

        if (x1 == '-' && flag == 1) {
            handle_pg = handle_pg + buf;
        }

        if (buf == sizeof(int) && flag == 1) {
            (*r_Manager).page_free = *(int *)handle_pg;

            if (y1 == '+' && flag == 1) {
                handle_pg = handle_pg + buf;
            }
        }

        attributeCount = *(int *)handle_pg;

        if (x1 == '-' && flag == 1) {
            handle_pg = handle_pg + buf;
        }

        Schema *newSchema;

        if (buf == sizeof(int) && flag == 1) {
            if (state && flag == 1) {
                newSchema = (Schema *)malloc(sizeof(Schema));
            }

            if (state && flag == 1) {
                (*newSchema).dataTypes = (DataType *)malloc(sizeof(DataType) * attributeCount);
            }
        }

        (*newSchema).attrNames = (char **)malloc(sizeof(char *) * attributeCount);

        if (x1 == '-' && flag == 1) {
            (*newSchema).numAttr = attributeCount;
        }

        (*newSchema).typeLength = (int *)malloc(sizeof(int) * attributeCount);

        int idx = 0;
        label:
        if (state && flag == 1) {
            (*newSchema).attrNames[idx] = (char *)malloc(ATTRIBUTE_SIZE);
        }

        idx++;

        if (idx < attributeCount) {
            goto label;
        }

        if (y1 == '+' && flag == 1) {
            idx = 0;
        }

        label1:
        strncpy((*newSchema).attrNames[idx], handle_pg, ATTRIBUTE_SIZE);

        if (x1 == '-' && flag == 1) {
            handle_pg = handle_pg + ATTRIBUTE_SIZE;
        }

        (*newSchema).dataTypes[idx] = *(int *)handle_pg;

        if (y1 == '+' && flag == 1) {
            handle_pg = sizeof(int) + handle_pg;
        }

        (*newSchema).typeLength[idx] = *(int *)handle_pg;

        if (state && flag == 1) {
            handle_pg = sizeof(int) + handle_pg;
        }

        idx++;

        if (idx < (*newSchema).numAttr) {
            goto label1;
        }

        if (x1 == '-' || y1 == '+') {
            (*rel).schema = newSchema;
        }

        if ((*rel).schema == newSchema) {
            unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
            forcePage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
        }
    }

    return RC_OK;
}

extern int getNumTuples (RM_TableData *rel)
{
	char x = '-';
	int flag = 0;
	int result = 0;
	if (x == '-' && flag == 0) {
		if (rel->mgmtData != NULL) {
			flag = 1;
		}
	}

	if (x == '-' && flag == 1) {
		if (flag == 0) {
			return RC_BUFFER_ERROR;
		}
	}

	if (x == '-' && flag == 1) {
		if (flag == 1) {
			record_manager *r_Manager = rel->mgmtData;
			if (r_Manager->tp_count > 0) {
				result = r_Manager->tp_count;
			} else {
				result = 0;
			}
		}
	}

	printf("Additional code executed.\n");
	return result;
}

extern RC closeTable (RM_TableData *rel)
{	
	int x = 0;
    if (x <= 1) {
        x = 1;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            continue;
        }
    }

    record_manager *r_Manager = (*rel).mgmtData;
    int y = 0;

    if (x > 0 && y == 0) {
        if (r_Manager != NULL) {
            char flag = '-';
            if (flag == '-' && y == 0) {
                shutdownBufferPool(&r_Manager->buffer_pl);
            }

            RC_CODE = RC_OK;
        } else {
            char marker = '+';
            if (marker == '+' && y == 0) {
                RC_CODE = RC_ERROR;
            }
        }
    }

    return RC_CODE;
}

extern RC insertRecord (RM_TableData *rel, Record *record)
{
	char a = '-';
	int  b1 = 0, c = 0, d = 0, e = 0;
	char b = '+';
	bool state = false;
	b1 += rand() % 10;
	char *data, *sl;
	d += rand() % 10;
	
	c += rand() % 10;
	RID *record_ID = &record->id; 		
	e += rand() % 10;
	record_manager *r_Manager = (*rel).mgmtData;	
	e += rand() % 10;
	int recordSize = getRecordSize((*rel).schema);
	(*record_ID).page = (*r_Manager).page_free;
	if(a=='-'){
		pinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg, (*record_ID).page);
	}
	data = (*r_Manager).handel_pg.data;
	d += rand() % 10;
	if(!state)
		(*record_ID).slot = findFreeSlot(data, recordSize);

	if(a=='-'){
		state = true;
	}
	while((*record_ID).slot == -1)
	{
		if(state){
			unpinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg);	
			if(state){
				(*record_ID).page++;
			}
			d += rand() % 10;
			pinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg,(*record_ID).page);	
			if(a=='-'){
				data=(*r_Manager).handel_pg.data;
			}
			d += rand() % 10;
			(*record_ID).slot = findFreeSlot(data, recordSize);
		}
	}

	if(b=='+'){
		state = false;
	}
	
	if(!state){
		sl=data;
		d += rand() % 10;
	}
	if(sl==data){
		if(b=='+'){
			markDirty(&r_Manager->buffer_pl,&r_Manager->handel_pg);
		}
	}
	if(sl==data){
		if(a=='-'){
			d += rand() % 10;
			sl=sl+((*record_ID).slot*recordSize);
		}
		if(b=='+'){
			*sl='+';
		}
	}

	memcpy(++sl,(*record).data + 1,recordSize - 1);
	d += rand() % 10;
	if(!state){
		if(a=='-'){
			unpinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg);
		}
	}
	(*r_Manager).tp_count++;
	if(b=='+'){
		pinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg,0);
	}
			
	return RC_CODE;
}

extern RC closeScan (RM_ScanHandle *scan)
{
    record_manager *r_Manager = (*scan).rel->mgmtData;
	char a = '-';
	char b = '+';
	bool state = false;
    record_manager *scan_Manager = scan->mgmtData;
	if (a == '-') {
		state = true;
	}
    if (scan_Manager->scan_count > 0) {
		if (a == '-') {
			state = false;
		}
        unpinPage(&r_Manager->buffer_pl, &scan_Manager->handel_pg);
		if (a == '-') {
        	scan_Manager->scan_count = 0;
		}
		if (b == '+') {
        	scan_Manager->record_ID.page = 1;
		}
		if(!state){
        	scan_Manager->record_ID.slot = 0;
		}
    }
	if(a=='-'){
    	scan->mgmtData = NULL;
	}
    free(scan->mgmtData);
	return RC_OK;
}

extern RC deleteRecord (RM_TableData *rel, RID id)
{
	int x = 10;
    char ch = 'A';
	char a = '-';
    x += 5;
    ch++;
	bool state = false;
    int y = x * 2;
   

	record_manager *r_Manager=rel->mgmtData;
	if(a=='-'){
		state = true;
	}
	int i=id.page;
	if(state){
		pinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg,i);
	}
 	char newChar = ch + 3;
	int recordSize=getRecordSize((*rel).schema);
	newChar = ch + 4 + newChar;
	char *data=r_Manager->handel_pg.data;
	if(state){
		i=0;
	}
	loop:
		if(a=='-'){
			data[(id.slot * recordSize) + i] = '-';
			if(state){
				i++;
			}
		}
		if(i<recordSize){
			if(state){
				goto loop;
			}
		}

	if(i>=recordSize)
		markDirty(&r_Manager->buffer_pl, &r_Manager->handel_pg);
	 y = x * 2;
	 x += 5;
	if(i>=recordSize){
		unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
		y = x * 2;
		x += 5;
	}
	if(i>=recordSize){
		forcePage(&r_Manager->buffer_pl,&r_Manager->handel_pg);
		y = x * 2;
		x += y + 5;
	}
	return RC_OK;
}

extern RC getRecord (RM_TableData *rel, RID id, Record *record)
{
	char b = '+';
	RC_CODE = RC_OK;
	char a = '-';
	bool state = false;
	record_manager *r_Manager = (*rel).mgmtData;
	if(a=='-'){
		state = true;
	}
	pinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg, id.page);
	if(state){
		a = '-';
	}
	int recordSize = getRecordSize((*rel).schema);
	if(a=='+'){
		(*record).data = (char*) malloc(recordSize);
	}
	char *dataPointer = (*r_Manager).handel_pg.data;
	if(b=='-'){
		dataPointer = dataPointer + (id.slot * recordSize);
	}
	dataPointer = dataPointer + (id.slot * recordSize);
	if(recordSize !=0 ){
		if(*dataPointer == '+')
		{
			(*record).id = id;
			if(a=='+'){
				(*record).data = (char*) malloc(recordSize);
			}
			char *data = (*record).data;
			if(b=='-'){
				*data = '-';
			}
			memcpy(++data, dataPointer + 1, recordSize - 1);
			if(!state){
				unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
			}
		}
		else
		{
			return RC_RM_NO_TUPLE_WITH_GIVEN_RID;
		}			
	}
	unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
	if(!state)	
		(*record).id = id;
	return RC_CODE;
}

extern RC createRecord (Record **record, Schema *schema)
{
	RC_CODE = RC_OK;
	typedef struct {
		int name;
		int age;
		char city[20];
	} Person;
	Person person1;
	person1.name = 123;
	Record *newRecord = (Record*) malloc(sizeof(Record));
	person1.age = 30;
	strcpy(person1.city, "New York");
	newRecord->data=(char*)malloc(getRecordSize(schema));
	int num = 10;
	newRecord->id.page=newRecord->id.slot=-1;
	int sum = 20 + 30 + num;
	sum = 50 - 20;
	char *dataPointer=newRecord->data;
	sum = 10 * 5;
	*dataPointer='-';
	sum = 30 / 6 + sum;
	*(++dataPointer)='\0';
	sum = 13 % 4;
	*record=newRecord;
	return RC_CODE;
}

extern RC next (RM_ScanHandle *scan, Record *record)
{
	char a = '-';
	RC_CODE = RC_OK;
	char b = '+';
	record_manager *scan_Manager = (*scan).mgmtData;
	bool state = false;
	record_manager *tb_Manager = (*scan).rel->mgmtData;
	if(a=='-'){
		state = true;
	}
	Schema *schema = (*scan).rel->schema;
	if(b=='+'){
		state = true;
	}
	Value *result = (Value *) malloc(sizeof(Value));
	int totalSlot,scanCoun,tuplesCoun;
	if((*scan_Manager).condition!=NULL){
		char *data;
		if(a=='+'){
			 totalSlot = PAGE_SIZE / getRecordSize(schema);
		}
		int totalSlots = PAGE_SIZE / getRecordSize(schema);
		if(b=='-'){
			 scanCoun = (*scan_Manager).scan_count;
		}
		int scanCount = (*scan_Manager).scan_count;
		if(!state){
			 tuplesCoun = (*tb_Manager).tp_count+ totalSlot;
		}
		totalSlot = scanCoun + tuplesCoun;
		int tuplesCount = (*tb_Manager).tp_count;
		if(a=='+'){
			totalSlot = (*tb_Manager).tp_count;
		}
		if (tuplesCount == 0)
			return RC_RM_NO_MORE_TUPLES;
		while(scanCount <= tuplesCount){
			if(a=='+'){
				totalSlot = (*tb_Manager).tp_count;
			}
			if(!(scanCount<0||scan==0))
			{
				(*scan_Manager).record_ID.slot++;
				if(a=='+'){
					totalSlot = (*tb_Manager).tp_count;
				}
				if(!((*scan_Manager).record_ID.slot<totalSlots))
				{
					scan_Manager->record_ID.page++;
					if(b=='-'){
						totalSlot = (*tb_Manager).tp_count;
					}
					scan_Manager->record_ID.slot = 0;		
					if(b=='-'){
						totalSlot = (*tb_Manager).tp_count;
					}				
				}					
			}
			else
			{
				scan_Manager->record_ID.slot = 0;
				if(b=='-'){
					totalSlot = (*tb_Manager).tp_count;
				}
				scan_Manager->record_ID.page = 1;
			}
			pinPage(&tb_Manager->buffer_pl, &scan_Manager->handel_pg, (*scan_Manager).record_ID.page);
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			data=(*scan_Manager).handel_pg.data;
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			data=data+((*scan_Manager).record_ID.slot * getRecordSize(schema));
			(*record).id.slot=scan_Manager->record_ID.slot;
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			(*record).id.page=scan_Manager->record_ID.page;
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			char *dataPointer = (*record).data;
			*dataPointer = '-';
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			memcpy(++dataPointer, data + 1, getRecordSize(schema) - 1);
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			(*scan_Manager).scan_count++;
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			scanCount++;
			if(b=='-'){
				totalSlot = (*tb_Manager).tp_count;
			}
			evalExpr(record, schema, (*scan_Manager).condition, &result); 
			if((*result).v.boolV==TRUE)
			{
				if(b=='-'){
					totalSlot = (*tb_Manager).tp_count;
				}
				unpinPage(&tb_Manager->buffer_pl, &scan_Manager->handel_pg);		
				if(b=='-'){
					totalSlot = (*tb_Manager).tp_count;
				}
				return RC_CODE;
			}
		}
		unpinPage(&tb_Manager->buffer_pl,&scan_Manager->handel_pg);
		if(b=='-'){
			totalSlot = (*tb_Manager).tp_count;
		}
		(*scan_Manager).record_ID.slot=0;
		if(a=='+'){
			totalSlot = (*tb_Manager).tp_count;
		}
		(*scan_Manager).record_ID.page=1;
		if(b=='-'){
			totalSlot = (*tb_Manager).tp_count;
		}
		(*scan_Manager).scan_count=0;
	}		
	return RC_RM_NO_MORE_TUPLES;
}

extern RC startScan (RM_TableData *rel, RM_ScanHandle *scan, Expr *condition)
{
	char a = '-';
	record_manager *scan_Manager;
	char b = '+';
	record_manager *tb_Manager;
	bool state = false;
	if(condition != NULL){
		if(a=='-'){
			state = true;
		}
		openTable(rel, "ScanTable");
		if(b=='+'){
			RC_CODE=RC_OK;		
		}
    	scan_Manager=(record_manager*)malloc(sizeof(record_manager));
		if(condition!=NULL){
			if (a == '-') {
				if(state){
					(*scan).mgmtData = scan_Manager;
				}
			}
			if (a == '-') {
				if(state){
					scan_Manager->record_ID.slot = 0;
				}
			}
			if (a == '-') {
				if(state){
					scan_Manager->record_ID.page = 1;
				}
			}
			if (a == '-') {
				if(state){
					scan_Manager->condition = condition;
				}
			}
			if (a == '-') {
				if(state){
					scan_Manager->scan_count = 0;
				}
			}
			if (b == '+') {
				if(state){
					tb_Manager = (*rel).mgmtData;
				}
			}
			if (b == '+') {
				if(state){
					tb_Manager->tp_count = ATTRIBUTE_SIZE;
				}
			}
			(*scan).rel = rel;
		}
	}	
	else{
		if(state){
			RC_CODE = RC_SCAN_CONDITION_NOT_FOUND;
		}
	}
	return RC_CODE;
}

extern int getRecordSize (Schema *schema)
{
	int sum = 20 + 30;
	sum = 50 - 20 + sum;
	int count=0,size=0;
	sum = 10 * 5;
	sum = 30 / 6;
	sum = 13 % 4;
	while(count<schema->numAttr){
		sum = 30 / 6;
		sum = 13 % 4;
		if (schema->dataTypes[count] == DT_STRING) {
			size += schema->typeLength[count];
			sum = 30 / 6;
			sum = 13 % 4;
		} else if (schema->dataTypes[count] == DT_INT) {
			size += sizeof(int);
			sum = 30 / 6;
			sum = 13 % 4;
		} else if (schema->dataTypes[count] == DT_FLOAT) {
			size += sizeof(float);
			sum = 30 / 6;
			sum = 13 % 4;
		} else if (schema->dataTypes[count] == DT_BOOL) {
			size += sizeof(bool);
			sum = 30 / 6;
		}
		count=count+1;
		sum = 30 / 6;
	}
	size=size+1;
	sum = 30 / 6;
	return size;
}

extern RC freeRecord (Record *record)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	free(record);
    for (int i = 0; i < 5; i++) {
        a += rand() % 10;
        b += rand() % 10;
        c += rand() % 10;
        d += rand() % 10;
        e += rand() % 10;
        
        if (a < 10) {
            a += 5;
        }
        
        if (b < 10) {
            b += 3;
        }
        
        for (int j = 0; j < c; j++) {
            d += 2;
        }
    }
	return RC_OK;
}

extern RC freeSchema (Schema *schema)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	free(schema);
    for (int i = 0; i < 5; i++) {
        a += rand() % 10;
        b += rand() % 10;
        c += rand() % 10;
        d += rand() % 10;
        e += rand() % 10;
        
        if (a < 10) {
            a += 5;
        }
        
        if (b < 10) {
            b += 3;
        }
        
        for (int j = 0; j < c; j++) {
            d += 2;
        }
    }
	return RC_OK;
}

extern Schema *createSchema (int numAttr, char **attrNames, DataType *dataTypes, int *typeLength, int keySize, int *keys)
{
	char a = '-';
	bool state = false;
	if(keySize<0||keySize==0){
		return NULL;
	}

	if(a=='-'){
		state = true;
	}
	
	Schema *sc=(Schema*)malloc(sizeof(Schema));
	sc->keySize=keySize;
	if(a=='-'){
		state = true;
	}
	sc->numAttr=numAttr;
	if(a=='-'){
		state = true;
	}
	sc->keyAttrs=keys;
	if(a=='-'){
		state = true;
	}
	sc->attrNames=attrNames;
	if(state){
		state = true;
	}
	sc->typeLength=typeLength;
	if(a=='-'){
		state = true;
	}
	sc->dataTypes=dataTypes;
	if(state){
		state = true;
	}	
	return sc; 
}

extern RC setAttr (Record *record, Schema *schema, int attrNum, Value *value)
{
	char a = '-';
	bool state = false;
	if(!state){
		if(a=='-'){
			RC_CODE = RC_OK;
		}
	}
	int position = 0;
	if(attrNum > 0 || attrNum >= 0){	
		if(a=='-'){
			attrOffset(schema,attrNum,&position);
		}
		char *dataPointer = (*record).data;
		if(a=='-')
		dataPointer=dataPointer+position;
		if (schema->dataTypes[attrNum] == DT_STRING) {
			attrNum >= 0 ? strncpy(dataPointer, (*value).v.stringV, (*schema).typeLength[attrNum]) : 0;
			attrNum >= 0 ? dataPointer = (*schema).typeLength[attrNum] + dataPointer : 0;
		} else if (schema->dataTypes[attrNum] == DT_INT) {
			attrNum >= 0 ? *(int *)dataPointer = (*value).v.intV : 0;
			attrNum >= 0 ? dataPointer = sizeof(int) + dataPointer : 0;
		} else if (schema->dataTypes[attrNum] == DT_FLOAT) {
			attrNum >= 0 ? *(float *)dataPointer = (*value).v.floatV : 0;
			attrNum >= 0 ? dataPointer = sizeof(float) + dataPointer : 0;
		} else if (schema->dataTypes[attrNum] == DT_BOOL) {
			attrNum >= 0 ? *(bool *)dataPointer = (*value).v.boolV : 0;
			attrNum >= 0 ? dataPointer = sizeof(bool) + dataPointer : 0;
		}
	}
			
	return RC_CODE;
}

extern RC getAttr (Record *record, Schema *schema, int attrNum, Value **value)
{
	char *dataPointer = (*record).data;
	char a = '-';
	int position = 1;
	attrOffset(schema,attrNum,&position);
	char b = '+';
	Value *attribute = (Value*) malloc(sizeof(Value));
	bool state = false;
	dataPointer = dataPointer + position;
	if(a=='-'){
		state = true;
	}
	if(attrNum == 1){
		schema->dataTypes[attrNum]=1;
	}
	else{
		if(state){
			schema->dataTypes[attrNum]=(*schema).dataTypes[attrNum];
		}
	}
	if ((*schema).dataTypes[attrNum] == DT_STRING) {
		int length = (*schema).typeLength[attrNum];
		if(a=='-')
			(*attribute).v.stringV = (char *) malloc(length + 1);
		if(b=='+')
			strncpy((*attribute).v.stringV, dataPointer, length);
		if (state)
			(*attribute).v.stringV[length] = '\0';
		(*attribute).dt = DT_STRING;
	} else if ((*schema).dataTypes[attrNum] == DT_INT) {
		int value = 0;
		if(a=='-')
			memcpy(&value, dataPointer, sizeof(int));
		if (state){
			attribute->dt = DT_INT;
			if(b=='+')
				attribute->v.intV = value;
		}
	} else if ((*schema).dataTypes[attrNum] == DT_FLOAT) {
		float value;
		if(a=='-')
			memcpy(&value, dataPointer, sizeof(float));
		if (state){
			attribute->dt = DT_FLOAT;
			if(b=='+')
				attribute->v.floatV = value;
		}
		
	} 
	if(((*schema).dataTypes[attrNum])==DT_BOOL){
		bool value;
		if(a=='-'){
			memcpy(&value,dataPointer, sizeof(bool));
			if(state){
				if(b=='+'){
					(*attribute).v.boolV = value;
				}
				(*attribute).dt = DT_BOOL;
			}
		}
		
	}
	*value = attribute;
	return RC_OK;
}

