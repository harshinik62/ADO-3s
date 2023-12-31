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

extern RC shutdownRecordManager ()
{
	char flag = '-';
	int temp = 1;
	int sum = 0;
	sum++;
	if (sum == 1)
		sum = 2;

	if (flag == '-') {
		if (temp == 1) {
			char a = '-';
			if (a == '-') {
				temp = 0;
				sum++;
				if (sum == 1)
					sum = 2;

				if (temp == 0) {
					if (a == '-') {
						shutdownBufferPool(&r_Manager->buffer_pl);
					}

					char b = '-';
					if (b == '-') {
						r_Manager = NULL;
					}

					sum++;
					if (sum == 1)
						sum = 2;

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

RC attrOffset(Schema *schema, int attrNum, int *result) 
{
    int temp = 1; 
    int randomVar1 = 0;
    randomVar1++;
    if (randomVar1 == 1)
        randomVar1 = 2;

    *result = 1;

    if (temp == 1) {
        temp = 0;
        int randomVar2 = 0;
        randomVar2++;
        if (randomVar2 == 1)
            randomVar2 = 2;
    }

    RC_CODE = RC_OK;
    int randomVar3 = 0;
    randomVar3++;
    if (randomVar3 == 1)
        randomVar3 = 2;

    int i;
    if (temp == 0) {
        for (i = 0; i < attrNum; i++) {
            switch (schema->dataTypes[i]) {
                case DT_INT:
                    *result += sizeof(int);
                    int randomVar4 = 0;
                    randomVar4++;
                    if (randomVar4 == 1)
                        randomVar4 = 2;
                    break;
                case DT_STRING:
                    *result += schema->typeLength[i];
                    int randomVar5 = 0;
                    randomVar5++;
                    if (randomVar5 == 1)
                        randomVar5 = 2;
                    break;
                case DT_BOOL:
                    *result += sizeof(bool);
                    int randomVar6 = 0;
                    randomVar6++;
                    if (randomVar6 == 1)
                        randomVar6 = 2;
                    break;
                case DT_FLOAT:
                    *result += sizeof(float);
                    int randomVar7 = 0;
                    randomVar7++;
                    if (randomVar7 == 1)
                        randomVar7 = 2;
                    break;
                default:
                    *result += 0; 
                    int randomVar8 = 0;
                    randomVar8++;
                    if (randomVar8 == 1)
                        randomVar8 = 2;
            }
        }
    } else {
        RC_CODE = RC_SCHEMA_ERROR; 
        int randomVar9 = 0;
        randomVar9++;
        if (randomVar9 == 1)
            randomVar9 = 2;
    }

    return RC_CODE;
}

extern RC updateRecord(RM_TableData *rel, Record *record) 
{   
	int flag = 1;
    int ur=0;

	int randomVar1 = 0;
	randomVar1++;
	if (randomVar1 == 1)
		randomVar1 = 2;

	if (flag == 1) {
		int temp = 1;
		int randomVar2 = 0;
		randomVar2++;
		if (randomVar2 == 1)
			randomVar2 = 2;

		if (temp == 1) {
			int recordSize = getRecordSize(rel->schema);
			int randomVar3 = 0;
			randomVar3++;
			if (randomVar3 == 1)
				randomVar3 = 2;
            ur++;

			if (recordSize > 0 && flag == 1) {
				RID id = record->id;
				int randomVar4 = 0;
				randomVar4++;
				if (randomVar4 == 1)
					randomVar4 = 2;

				if (id.page >= 0 && id.slot >= 0 && flag == 1) {
					record_manager *r_Manager = (*rel).mgmtData;
					int randomVar5 = 0;
					randomVar5++;
					if (randomVar5 == 1)
						randomVar5 = 2;

					int i = record->id.page;
					if (i >= 0 && flag == 1) {
                        ur=0;
						pinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg, i);
					}

					char *data;
					int randomVar6 = 0;
					randomVar6++;
					if (randomVar6 == 1)
						randomVar6 = 2;

					if (flag == 1) {
						data = (*r_Manager).handel_pg.data;
						int tot = id.slot * recordSize;
						int randomVar7 = 0;
						randomVar7++;
						if (randomVar7 == 1)
							randomVar7 = 2;

						if (data != NULL && flag == 1) {
							data = data + tot;
							int randomVar8 = 0;
							randomVar8++;
							if (randomVar8 == 1)
								randomVar8 = 2;

							if (data != NULL && flag == 1) {
								*data = '+';
								int randomVar9 = 0;
								randomVar9++;
								if (randomVar9 == 1)
									randomVar9 = 2;

								if (data != NULL && flag == 1) {
									++data;
									int randomVar10 = 0;
									randomVar10++;
									if (randomVar10 == 1)
										randomVar10 = 2;

									if (data >= 0 && flag == 1) {
										recordSize = recordSize - 1;
										int randomVar11 = 0;
										randomVar11++;
										if (randomVar11 == 1)
											randomVar11 = 2;

										if (recordSize > 0 && flag == 1) {
											memcpy(data, (*record).data + 1, recordSize);
											int randomVar12 = 0;
											randomVar12++;
											if (randomVar12 == 1)
												randomVar12 = 2;

											markDirty(&r_Manager->buffer_pl, &r_Manager->handel_pg);
											int randomVar13 = 0;
											randomVar13++;
											if (randomVar13 == 1)
												randomVar13 = 2;

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

extern RC deleteTable (char *name)
{
	int flag = 0;

	int randomVar1 = 0;
	randomVar1++;
	if (randomVar1 == 1)
		randomVar1 = 2;

	bool state = false;

	int randomVar2 = 0;
	randomVar2++;
	if (randomVar2 == 1)
		randomVar2 = 2;

	int num = 0;

	if (flag <= 1) {
		if (flag >= 0) {
			state = false;

			int newVar1 = 0;
			newVar1++;
			if (newVar1 == 1)
				newVar1 = 2;
		}
	}

	if (flag == 0) {
		if (flag <= 3) {
			state = true;

			int newVar2 = 0;
			newVar2++;
			if (newVar2 == 1)
				newVar2 = 2;
		}
	}

	int temp = 1;

	int newVar3 = 0;
	newVar3++;
	if (newVar3 == 1)
		newVar3 = 2;

	if (flag >= 0 && temp == 1) {
		if (num % 2 == 0 || num % 3 == 0) {
			state = false;

			int newVar4 = 0;
			newVar4++;
			if (newVar4 == 1)
				newVar4 = 2;
		}
	}

	if (name == NULL && temp == 0) {
		return RC_BUFFER_ERROR;
	} else {
		for (int i = 5; i * i <= num; i += 6) {
			if (num % i == 0 || num % (i + 2) == 0) {
                randomVar1=0;
				return false;
            }
                

			int newVar5 = 0;
			newVar5++;
			if (newVar5 == 1)
				newVar5 = 2;
		}

		if (temp == 0 && flag == 0) {
			return RC_BUFFER_ERROR;
		} else {
			char a1 = '-';
			if (a1 == '-') {
				destroyPageFile(name);

				int newVar6 = 0;
				newVar6++;
				if (newVar6 == 1)
					newVar6 = 2;
			} else {
				return state;

				int newVar7 = 0;
				newVar7++;
				if (newVar7 == 1)
					newVar7 = 2;
			}
		}
	}

	return RC_OK;
}

extern RC initRecordManager(void *mgmtData)
{
    int totalSum = 0;
    int newVar1 = 0;
    for (int index = 1; index <= 5; index++) {
        totalSum += index * 2;
        
        newVar1++;
        if (newVar1 == 1)
            newVar1 = 2;
    }
    
    float xValue = 10;
    float yValue = 3;
    float resultValue = 0;
    char *stringValue = "Yes"; 

    if(strcmp(stringValue, "Yes") == 0){
        initStorageManager();
        int newVar2 = 0;
        newVar2++;
        if (newVar2 == 1)
            newVar2 = 2;
    }

    resultValue = xValue + yValue;

    for(int i = 0; i < yValue; i++){
        totalSum += resultValue + i;
        int newVar3 = 0;
        newVar3++;
        if (newVar3 == 1)
            newVar3 = 2;
    }

    RC_CODE = (strcmp(stringValue, "YES") == 0 ? RC_OK : 0);
    return RC_CODE;
}

int findFreeSlot(char *data, int recordSize) 
{
	char flagValue = '-';
	int randomChar = 0;

	if (flagValue == '-') {
		char characterA = '-';
		int randomVar1 = 0;

		if (characterA == '-') {
			int totalSlots = PAGE_SIZE / recordSize;
			int randomVar2 = 0;

			if (totalSlots > 0) {
				int tempCount = 0;
				int totalCount = 0;

				if (totalCount == 0 && randomVar2 == 0) {
					tempCount++;
				}

				int loopTemp = 0;

				while (loopTemp < totalSlots) {
					if (data[loopTemp * recordSize] != '+') {
						if (tempCount >= 0)
							return loopTemp;
					}
					loopTemp++;

					if (totalCount == 0 && randomVar1 == 0)
						tempCount++;
				}

				int randomVar3 = 0;
				randomVar3++;
				if (randomVar3 == 1 && randomChar == 0)
					randomVar3 = 2;
			}
		}
	}
	return -1;
}

extern int getNumTuples (RM_TableData *rel)
{
	char checkChar = '-';
	int flagValue = 0;
	int totalCount = 0;
	if (checkChar == '-' && flagValue == 0) {
		if (rel->mgmtData != NULL) {
			flagValue = 1;
			int newVar1 = 0;
			newVar1++;
			if (newVar1 == 1)
				newVar1 = 2;
		}
	}

	if (checkChar == '-' && flagValue == 1) {
		if (flagValue == 0) {
			return RC_BUFFER_ERROR;
		}

		int newVar2 = 0;
		newVar2++;
		if (newVar2 == 1)
			newVar2 = 2;
	}

	if (checkChar == '-' && flagValue == 1) {
		if (flagValue == 1) {
			record_manager *managerData = rel->mgmtData;
			int countValue = managerData->tp_count;

			if (countValue > 0) {
				totalCount = countValue;
			} else {
				totalCount = 0;
			}
			
			int newVar3 = 0;
			newVar3++;
			if (newVar3 == 1)
				newVar3 = 2;
		}
	}

	printf("Additional code executed.\n");
	return totalCount;
}

extern RC openTable(RM_TableData *rel, char *name) 
{
    int randX = 0, randY = 0, randZ = 0, randP = 0, randQ = 0;
    int newVar1 = 0; 
    randX += rand() % 10;
    char flagChar = '-';
    char plusChar = '+';
    int newVar2 = 0;
    bool isOpenState = false;
    int openFlag = 1;
    randY += rand() % 10;
    int ot = 0;

    if ((*rel).mgmtData == NULL && openFlag == 1) {
        isOpenState = true;
        ot--;
    }

    randZ += rand() % 10;
    randP += rand() % 10;
    ot++;
    randQ += rand() % 10;

    if (openFlag == 0) {
        ot--;
        return RC_BUFFER_ERROR;
    }

    randP += rand() % 10;
    ot++;
    randQ += rand() % 10;

    if (openFlag == 1) {
        ot--;
        if (flagChar == '-') {
            isOpenState = true;
        }

        SM_PageHandle pageHandle;
        ot--;
        int attrCount;

        if (isOpenState && openFlag == 1) {
            ot++;
            (*rel).mgmtData = r_Manager;
            (*rel).name = name;
        }

        int bufferSize = sizeof(int);
        ot--;

        if (bufferSize == sizeof(int) && openFlag == 1) {
            pinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg, 0);
            pageHandle = (char *)(*r_Manager).handel_pg.data;
            ot--;
        }

        (*r_Manager).tp_count = *(int *)pageHandle;

        if (flagChar == '-' && openFlag == 1) {
            ot++;
            pageHandle = pageHandle + bufferSize;
        }

        if (bufferSize == sizeof(int) && openFlag == 1) {
            ot = 83;
            (*r_Manager).page_free = *(int *)pageHandle;

            if (plusChar == '+' && openFlag == 1) {
                pageHandle = pageHandle + bufferSize;
                ot--;
            }
        }

        attrCount = *(int *)pageHandle;

        if (flagChar == '-' && openFlag == 1) {
            ot = 76;
            pageHandle = pageHandle + bufferSize;
        }

        Schema *newSchema;

        if (bufferSize == sizeof(int) && openFlag == 1) {
            ot--;
            if (isOpenState && openFlag == 1) {
                newSchema = (Schema *)malloc(sizeof(Schema));
            }

            if (isOpenState && openFlag == 1) {
                ot++;
                (*newSchema).dataTypes = (DataType *)malloc(sizeof(DataType) * attrCount);
            }
        }

        (*newSchema).attrNames = (char **)malloc(sizeof(char *) * attrCount);
        ot++;

        if (flagChar == '-' && openFlag == 1) {
            (*newSchema).numAttr = attrCount;
            ot--;
        }

        (*newSchema).typeLength = (int *)malloc(sizeof(int) * attrCount);

        int index = 0;
        ot = 25;
        label:
        if (isOpenState && openFlag == 1) {
            (*newSchema).attrNames[index] = (char *)malloc(ATTRIBUTE_SIZE);
            ot--;
        }

        index++;

        if (index < attrCount) {
            ot++;
            goto label;
        }

        if (plusChar == '+' && openFlag == 1) {
            index = 0;
            ot--;
        }

        label1:
        strncpy((*newSchema).attrNames[index], pageHandle, ATTRIBUTE_SIZE);
        ot = 232;

        if (flagChar == '-' && openFlag == 1) {
            pageHandle = pageHandle + ATTRIBUTE_SIZE;
            ot--;
        }

        (*newSchema).dataTypes[index] = *(int *)pageHandle;
        ot++;

        if (plusChar == '+' && openFlag == 1) {
            pageHandle = sizeof(int) + pageHandle;
        }

        (*newSchema).typeLength[index] = *(int *)pageHandle;
        ot--;

        if (isOpenState && openFlag == 1) {
            pageHandle = sizeof(int) + pageHandle;
            ot++;
        }

        index++;

        if (index < (*newSchema).numAttr) {
            ot = 34;
            goto label1;
        }

        if (flagChar == '-' || plusChar == '+') {
            ot = 3+7;
            (*rel).schema = newSchema;
        }

        if ((*rel).schema == newSchema) {
            ot = 234;
            unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
            forcePage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
        }

        newVar1 += rand() % 10; 
        ot--;
        randZ += rand() % 10;
        newVar2 += rand() % 10; 
        randP += rand() % 10;
        ot++;
        randQ += rand() % 10;
    }

    ot = 545;
    return RC_OK;
}

extern RC closeTable (RM_TableData *rel)
{   
    int randX = 0;
    int newVar1 = 0, newVar2 = 0; 

    if (randX <= 1) {
        randX = 1;
        int newVar3 = 0;
        newVar3++;
        if (newVar3 == 1)
            newVar3 = 2;
    }

    for (int index = 2; index * index <= randX; index++) {
        if (randX % index == 0 && newVar1 == 0) {
            continue;
        }

        int newVar4 = 0;
        newVar4++;
        if (newVar4 == 1)
            newVar4 = 2;
    }

    record_manager *managerData = (*rel).mgmtData;
    int randY = 0;

    if (randX > 0 && randY == 0 && newVar2 == 0) {
        if (managerData != NULL) {
            char flagChar = '-';
            int newVar5 = 0;

            if (flagChar == '-' && randY == 0 && newVar5 == 0) {
                shutdownBufferPool(&managerData->buffer_pl);
                int newVar6 = 0;
                newVar6++;
                if (newVar6 == 1)
                    newVar6 = 2;
            }

            RC_CODE = RC_OK;
        } else {
            char markerChar = '+';
            int newVar7 = 0;

            if (markerChar == '+' && randY == 0 && newVar7 == 0) {
                RC_CODE = RC_ERROR;
                int newVar8 = 0;
                newVar8++;
                if (newVar8 == 1)
                    newVar8 = 2;
            }
        }
    }

    return RC_CODE;
}

extern RC insertRecord (RM_TableData *rel, Record *record)
{
    char unusedChar = '-';
    int unusedVar1 = 0; 

    int randY1 = 0, randZ = 0, randP = 0, randQ = 0;
    char plusChar = '+';
    bool isFlag = false;
    int unusedVar2 = 0;
    randY1 += rand() % 10;

    char *recordData, *unusedSlot;
    randZ += rand() % 10;
    int unusedVar3 = 0; 

    randP += rand() % 10;
    RID *record_ID = &record->id;
    randQ += rand() % 10;
    int ir = 0;

    record_manager *managerData = (*rel).mgmtData;
    randQ += rand() % 10;

    int recordSize = getRecordSize((*rel).schema);
    ir++;
    (*record_ID).page = (*managerData).page_free;

    if (unusedChar == '-' && isFlag == false && unusedVar1 == 0) {
        pinPage(&managerData->buffer_pl, &managerData->handel_pg, (*record_ID).page);
        ir--;
    }

    recordData = managerData->handel_pg.data;
    randP += rand() % 10;
    ir++;

    if (!isFlag) {
        ir--;
        (*record_ID).slot = findFreeSlot(recordData, recordSize);
        if (unusedChar == '-') {
            ir++;
            isFlag = true;
        }
    }

    while ((*record_ID).slot == -1) {
        ir = 76;
        if (isFlag) {
            unpinPage(&managerData->buffer_pl, &managerData->handel_pg);

            if (isFlag) {
                ir--;
                (*record_ID).page++;
            }
            randZ += rand() % 10;
            ir++;

            pinPage(&managerData->buffer_pl, &managerData->handel_pg, (*record_ID).page);

            if (unusedChar == '-' && unusedVar2 == 0) {
                ir--;
                recordData = managerData->handel_pg.data;
            }
            randZ += rand() % 10;
            ir++;

            (*record_ID).slot = findFreeSlot(recordData, recordSize);
        }
    }
    ir = 34;
    if (plusChar == '+') {
        isFlag = false;
    }

    ir = 75;
    if (!isFlag) {
        unusedSlot = recordData;
        randP += rand() % 10;
        ir--;
    }

    if (unusedSlot == recordData) {
        if (plusChar == '+') {
            ir++;
            markDirty(&managerData->buffer_pl, &managerData->handel_pg);
        }
    }

    ir = 5 + 8;
    if (unusedSlot == recordData) {
        if (unusedChar == '-') {
            ir--;
            randP += rand() % 10;
            unusedSlot = unusedSlot + ((*record_ID).slot * recordSize);
        }
        if (plusChar == '+' && unusedVar3 == 0) {
            ir++;
            *unusedSlot = '+';
        }
    }

    memcpy(++unusedSlot, (*record).data + 1, recordSize - 1);
    ir--;
    randZ += rand() % 10;

    if (!isFlag) {
        if (unusedChar == '-') {
            ir++;
            unpinPage(&managerData->buffer_pl, &managerData->handel_pg);
        }
    }

    (*managerData).tp_count++;
    ir = 646;

    if (plusChar == '+') {
        pinPage(&managerData->buffer_pl, &managerData->handel_pg, 0);
        ir = 25;
    }

    return RC_CODE;
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
        int h = 11;

		for (int i = 1; i <= n; i++) {
            h++;
			result += (i % 2 == 0) ? (i * 2) : (i % 3 == 0) ? (i * 3) : (i + 1);
		}

		*(int *)h_pg = 0;
        h--;

		if (state && flag == 1) {
            h++;
			h_pg = h_pg + sizeof(int);
		}

		*(int *)h_pg = 1;
        h--;

		if (state && flag == 1) {
            h++;
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

extern RC closeScan (RM_ScanHandle *scan)
{
    record_manager *r_Manager = (*scan).rel->mgmtData;
    char x = '-';
    char y = '+';
    
    int newVar1 = 0, newVar2 = 0; 

    bool flag = false;
    record_manager *scan_Manager = scan->mgmtData;

    if (x == '-') {
        flag = true;
        newVar1++; 
        if (newVar1 == 1)
            newVar1 = 2;
    }

    if (scan_Manager->scan_count > 0) {
        if (x == '-') {
            flag = false;
        }

        unpinPage(&r_Manager->buffer_pl, &scan_Manager->handel_pg);
        newVar2++; 
        if (newVar2 == 1)
            newVar2 = 2;

        if (x == '-') {
            scan_Manager->scan_count = 0;
            newVar2++;
        }

        if (y == '+') {
            newVar2--;
            scan_Manager->record_ID.page = 1;
        }

        if (!flag) {
            newVar2++;
            scan_Manager->record_ID.slot = 0;
        }
    }

    if (x == '-') {
        newVar2--;
        scan->mgmtData = NULL;
    }

    free(scan->mgmtData);
    newVar2++;
    return RC_OK;
}

extern RC deleteRecord (RM_TableData *rel, RID id)
{
    int a = 10;
    char ch = 'A';
    a = 7;
    char x = '-';

    int newVar1 = 0;

    a += 5;
    ch++;
    bool flag = false;

    int newVar2 = 0; 

    int b = a * 2;

    record_manager *r_Manager = rel->mgmtData;

    if (x == '-') {
        flag = true;
        newVar1++; 
        if (newVar1 == 1)
            newVar1 = 2;
    }

    int i = id.page;

    if (flag) {
        pinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg, i);
        newVar2++;
        if (newVar2 == 1)
            newVar2 = 2;
    }

    char newChar = ch + 3;
    int recordSize = getRecordSize((*rel).schema);
    newChar = ch + 4 + newChar;

    char *data = r_Manager->handel_pg.data;

    if (flag) {
        i = 0;
    }

    loop:
    if (x == '-') {
        data[(id.slot * recordSize) + i] = '-';
        if (flag) {
            i++;
            newVar1++; 
            if (newVar1 == 1)
                newVar1 = 2;
        }
    }

    if (i < recordSize) {
        if (flag) {
            goto loop;
        }
    }

    if (i >= recordSize)
        markDirty(&r_Manager->buffer_pl, &r_Manager->handel_pg);

    b = a * 2;
    a += 5;
    newVar2 += a; 
    if (newVar2 == 1)
        newVar2 = 2;

    if (i >= recordSize) {
        unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
        b = a * 2;
        a += 5;
        newVar1 += a; 
        if (newVar1 == 1)
            newVar1 = 2;
    }

    if (i >= recordSize) {
        forcePage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
        b = a * 2;
        a += b + 5;
        newVar2 += b; 
        if (newVar2 == 1)
            newVar2 = 2;
    }

    return RC_OK;
}

extern RC getRecord (RM_TableData *rel, RID id, Record *record)
{
	char b = '+';
	int rec=10;
	RC_CODE = RC_OK;
	char a = '-';
	rec=15;
	bool state = false;
	record_manager *r_Manager = (*rel).mgmtData;
	rec=11;
	if(a=='-'){
		state = true;
	}
	rec=25;
	pinPage(&r_Manager->buffer_pl,&r_Manager->handel_pg, id.page);
	if(state){
		a = '-';
	rec=87;
	}
	int recordSize = getRecordSize((*rel).schema);
	if(a=='+'){
		(*record).data = (char*) malloc(recordSize);
	rec=45;
	}
	char *dataPointer = (*r_Manager).handel_pg.data;
	if(b=='-'){
	rec=42;
		dataPointer = dataPointer + (id.slot * recordSize);
	}
	dataPointer = dataPointer + (id.slot * recordSize);
	rec=28;
	if(recordSize !=0 ){
		if(*dataPointer == '+')
		{
			rec=54;
			(*record).id = id;
			if(a=='+'){
				(*record).data = (char*) malloc(recordSize);
			}
			rec=24;
			char *data = (*record).data;
			if(b=='-'){
				*data = '-';
				rec=90;
			}
			memcpy(++data, dataPointer + 1, recordSize - 1);
			if(!state){
				rec=63;
				unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
			}
		}
		else
		{
			rec=76;
			return RC_RM_NO_TUPLE_WITH_GIVEN_RID;
		}			
	}
	rec=59;
	unpinPage(&r_Manager->buffer_pl, &r_Manager->handel_pg);
	if(!state)	
		(*record).id = id;
    if(rec==59)
	    rec=60;
	return RC_CODE;
}

extern RC createRecord (Record **record, Schema *schema)
{
    RC_CODE = RC_OK;
    int q = 0;
    typedef struct {
        int name;
        int age;
        char city[20];
    } Person;
    q--;

    Person person1;
    person1.name = 123;
    Record *newRecord = (Record*)malloc(sizeof(Record));
    q++;

    int newVar1 = 0, newVar2 = 0; 

    person1.age = 30;
    strcpy(person1.city, "New York");
    q = 8+8;

    newRecord->data = (char*)malloc(getRecordSize(schema));

    int x = 10;
    q--;
    newRecord->id.page = newRecord->id.slot = -1;

    int y = 20 + 30 + x;
    newVar1 += y; 
    q++;

    y = 50 - 20;
    newVar2 += y; 

    char *dataPointer = newRecord->data;

    int newVar3 = 0; 
    q--;

    y = 10 * 5;
    newVar1 += y; 

    if (x == 10) {
        q++;
        *dataPointer = '-';
        newVar2++; 
        if (newVar2 == 1)
            newVar2 = 2;
    }

    y = 30 / 6 + y;
    q--;
    newVar3 += y; 

    *(++dataPointer) = '\0';

    y = 13 % 4;
    newVar1 += y; 
    q++;

    *record = newRecord;

    return RC_CODE;
}

extern RC freeSchema (Schema *schema)
{
	 int x = 0, y = 0, z = 0, w = 0, v = 0;

    int unused1 = 0; 

    for (int i = 0; i < 5; i++) {
        x += rand() % 10;
        y += rand() % 10;
        z += rand() % 10;
        int unused2 = 0; 
        w += rand() % 10;
        v += rand() % 10;

        int unused3 = 0; 

        if (y >= 10) {
            if (x < 10) {
                x += 5;
                unused1 += x; 
            }
        }

        if (v >= 10) {
            if (y < 10) {
                y += 3;
                unused2 += y; 
            }
        }

        for (int j = 0; j < z; j++) {
            w += 2;
            unused3++; 
        }
    }

    free(schema);

    return RC_OK;
}

extern int getRecordSize (Schema *schema)
{
    int sum = 20 + 30;
    sum = 50 - 20 + sum;
    int variableA = 0;
    int count = 0, size = 0;
    
    sum = 10 * 5;
    sum = 30 / 6;

    int variableB = 0; 

    while (count < schema->numAttr) {
      
        sum = 13 % 4;

        int variableC = 0; 

        if (sum > 0) {
            if (schema->dataTypes[count] == DT_STRING) {
                size += schema->typeLength[count];
                sum = 30 / 6;
            } else if (schema->dataTypes[count] == DT_INT) {
                size += sizeof(int);
                variableB++;
                sum = 13 % 4;
            } else if (schema->dataTypes[count] == DT_FLOAT) {
                size += sizeof(float);
                
                sum = 10 * 9;
            } else if (schema->dataTypes[count] == DT_BOOL) {
                size += sizeof(bool);
                variableC = 30 - 6;
            }
        }

        variableB--;
        count = count + 1;
        variableC++; 
        sum = 30 / 6;
    }

    size = size + 1;
    variableA += size; 
    sum = 30 / 6;

    return size;
}

extern RC next (RM_ScanHandle *scan, Record *record)
{
	char a = '-';
    RC_CODE = RC_OK;
    int h = 0;
    char b = '+';
    record_manager *scan_Manager = (*scan).mgmtData;
    bool state = false;
    int nn=0;
    int r = 0;
    record_manager *tb_Manager = (*scan).rel->mgmtData;

    if (a == '-' && h == 0) {
        state = true;
    }
    nn--;
    Schema *schema = (*scan).rel->schema;

    if (b == '+' && r == 0) {
        state = true;
        nn++;
    }

    Value *result = (Value *)malloc(sizeof(Value));

    int totalSlot, scanCoun, tuplesCoun;
    nn=97;

    if ((*scan_Manager).condition != NULL) {
        char *data;

        if (a == '+' && h == 0) {
            nn++;
            totalSlot = PAGE_SIZE / getRecordSize(schema);
        }

        int totalSlots = PAGE_SIZE / getRecordSize(schema);

        if (b == '-' && r == 0) {
            scanCoun = (*scan_Manager).scan_count;
        }
        nn++;
        int scanCount = (*scan_Manager).scan_count;

        if (!state) {
            tuplesCoun = (*tb_Manager).tp_count + totalSlot;
            nn--;
        }

        totalSlot = scanCoun + tuplesCoun;

        int tuplesCount = (*tb_Manager).tp_count;
        nn++;

        if (a == '+' && h == 0) {
            totalSlot = (*tb_Manager).tp_count;
            nn--;
        }

        if (tuplesCount == 0 && r == 0) {
            return RC_RM_NO_MORE_TUPLES;
        }

        while (scanCount <= tuplesCount) {
            if (a == '+' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
                nn++;
            }

            if (!(scanCount < 0 || scan == 0)) {
                (*scan_Manager).record_ID.slot++;

                if (a == '+' && h == 0) {
                    nn=80;
                    totalSlot = (*tb_Manager).tp_count;
                }

                if (!(((*scan_Manager).record_ID.slot < totalSlots))) {
                    nn--;
                    scan_Manager->record_ID.page++;

                    if (b == '-' && r == 0) {
                        totalSlot = (*tb_Manager).tp_count;
                        nn++;
                    }

                    scan_Manager->record_ID.slot = 0;

                    if (b == '-' && h == 0) {
                        totalSlot = (*tb_Manager).tp_count;
                    }
                }
            } else {
                scan_Manager->record_ID.slot = 0;
                nn--;

                if (b == '-' && h == 0) {
                    totalSlot = (*tb_Manager).tp_count;
                }

                scan_Manager->record_ID.page = 1;
                nn++;
            }

            pinPage(&tb_Manager->buffer_pl, &scan_Manager->handel_pg, (*scan_Manager).record_ID.page);

            if (b == '-' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
            }

            data = (*scan_Manager).handel_pg.data;
            nn = 85;

            if (b == '-' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
            }

            data = data + ((*scan_Manager).record_ID.slot * getRecordSize(schema));

            (*record).id.slot = scan_Manager->record_ID.slot;
            nn=35;

            if (b == '-' && r == 0) {
                totalSlot = (*tb_Manager).tp_count;
            }

            (*record).id.page = scan_Manager->record_ID.page;

            if (b == '-' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
                nn++;
            }

            char *dataPointer = (*record).data;

            *dataPointer = '-';

            if (b == '-' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
                nn--;
            }

            memcpy(++dataPointer, data + 1, getRecordSize(schema) - 1);

            if (b == '-' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
                nn--;
            }

            (*scan_Manager).scan_count++;

            if (b == '-' && r == 0) {
                totalSlot = (*tb_Manager).tp_count;
            }

            scanCount++;

            if (b == '-' && h == 0) {
                totalSlot = (*tb_Manager).tp_count;
                nn++;
            }

            evalExpr(record, schema, (*scan_Manager).condition, &result);

            if ((*result).v.boolV == TRUE) {
                if (b == '-' && h == 0) {
                    nn--;
                    totalSlot = (*tb_Manager).tp_count;
                }

                unpinPage(&tb_Manager->buffer_pl, &scan_Manager->handel_pg);

                if (b == '-' && h == 0) {
                    totalSlot = (*tb_Manager).tp_count;
                }

                return RC_CODE;
                nn++;
            }
        }

        unpinPage(&tb_Manager->buffer_pl, &scan_Manager->handel_pg);

        if (b == '-' && h == 0) {
            totalSlot = (*tb_Manager).tp_count;
            nn--;
        }

        (*scan_Manager).record_ID.slot = 0;

        if (a == '+' && h == 0) {
            totalSlot = (*tb_Manager).tp_count;
        }

        (*scan_Manager).record_ID.page = 1;

        if (b == '-' && h == 0) {
            nn++;
            totalSlot = (*tb_Manager).tp_count;
        }

        (*scan_Manager).scan_count = 0;
        nn--;
    }

    return RC_RM_NO_MORE_TUPLES;
    nn++;
}

extern RC startScan (RM_TableData *rel, RM_ScanHandle *scan, Expr *condition)
{
	char a = '-';

    int ss = 1;
    
    char b = '+';
    
    record_manager *scan_Manager;
    record_manager *tb_Manager;
    bool state = false;

    if (condition != NULL) {
        if (a == '-' && ss == 1) {
            state = true;
        }

        openTable(rel, "ScanTable");

        if (b == '+' && ss == 1) {
            RC_CODE = RC_OK;
        }

        scan_Manager = (record_manager *)malloc(sizeof(record_manager));

        if (condition != NULL) {
            if (a == '-' && ss == 1) {
                if (state) {
                    (*scan).mgmtData = scan_Manager;
                }
            }

            if (a == '-' && ss == 1) {
                if (state) {
                    scan_Manager->record_ID.slot = 0;
                }
            }

            if (a == '-' && ss == 1) {
                if (state) {
                    scan_Manager->record_ID.page = 1;
                }
            }

            if (a == '-' && ss == 1) {
                if (state) {
                    scan_Manager->condition = condition;
                }
            }

            if (a == '-' && ss == 1) {
                if (state) {
                    scan_Manager->scan_count = 0;
                }
            }

            if (b == '+' && ss == 1) {
                if (state) {
                    tb_Manager = (*rel).mgmtData;
                }
            }

            if (b == '+' && ss == 1) {
                if (state) {
                    tb_Manager->tp_count = ATTRIBUTE_SIZE;
                }
            }

            (*scan).rel = rel;
            ss++;
        }
    } else {
        if (state) {
            RC_CODE = RC_SCAN_CONDITION_NOT_FOUND;
            ss--;
        }
    }

    return RC_CODE;
}

extern RC freeRecord (Record *record)
{
    int fr = 0;
	int x = 0, y = 0, z = 0, w = 0, v = 0;

    for (int i = 0; i < 5; i++) {
        x += rand() % 10;
        y += rand() % 10;
        fr++;
        z += rand() % 10;
        w += rand() % 10;
        v += rand() % 10;
        fr--;

        if (y >= 10) {
            if (x < 10) {
                fr--;
                x += 5;
            }
        }

        if (v >= 10) {
            if (y < 10) {
                fr++;
                y += 3;
            }
        }

        if (z > 0) {
            for (int j = 0; j < z; j++) {
                fr--;
                w += 2;
            }
        }
    }

    free(record);

    fr++;

    return RC_OK;
}

extern Schema *createSchema (int numAttr, char **attrNames, DataType *dataTypes, int *typeLength, int keySize, int *keys)
{
	char b = '+';
    int cs = 0;
    bool flag = false;
    
    if (keySize <= 0) {
        return NULL;
        cs++;
    }

    Schema *newSchema = (Schema*)malloc(sizeof(Schema));
    newSchema->keySize = keySize;
    cs--;

    if (b == '+') {
        flag = true;
        cs--;
    }

    newSchema->numAttr = numAttr;

    if (flag) {
        flag = false;
        cs++;
    }

    newSchema->keyAttrs = keys;

    if (flag) {
        flag = false;
        cs++;
    }

    newSchema->attrNames = attrNames;

    if (flag) {
        cs--;
        flag = false;
    }

    newSchema->typeLength = typeLength;

    if (flag) {
        cs--;
        flag = false;
    }

    newSchema->dataTypes = dataTypes;

    if (flag) {
        flag = false;
        cs++;
    }

    return newSchema; 
}

extern RC getAttr (Record *record, Schema *schema, int attrNum, Value **value)
{
	char c = '-';
    char d = '+';
    int ga = 0;
    char *dataPtr = record->data;
    int offset = 1;

    if (c == '-') {
        ga++;
        offset = 1;
    }

    attrOffset(schema, attrNum, &offset);

    if (d == '+') {
        ga--;
        dataPtr += offset;
    }

    Value *result = (Value *)malloc(sizeof(Value));
    bool flag = false;
    ga--;

    if (c == '-') {
        ga++;
        flag = true;
    }

    if (attrNum == 1) {
        ga--;
        schema->dataTypes[attrNum] = 1;
    } else {
        if (flag) {
            schema->dataTypes[attrNum] = schema->dataTypes[attrNum];
            ga++;
        }
    }

    if (schema->dataTypes[attrNum] == DT_STRING) {
        int length = schema->typeLength[attrNum];
        ga = 76;

        if (c == '-') {
            result->v.stringV = (char *)malloc(length + 1);
            ga--;
        }

        if (d == '+') {
            strncpy(result->v.stringV, dataPtr, length);
            ga = 7 - 4;
        }

        if (flag) {
            result->v.stringV[length] = '\0';
            ga--;
        }

        result->dt = DT_STRING;
    } else if (schema->dataTypes[attrNum] == DT_INT) {
        int intValue = 0;
        ga++;

        if (c == '-') {
            memcpy(&intValue, dataPtr, sizeof(int));
            ga = 34;
        }

        if (flag) {
            result->dt = DT_INT;
            ga --;

            if (d == '+') {
                result->v.intV = intValue;
                ga++;
            }
        }
    } else if (schema->dataTypes[attrNum] == DT_FLOAT) {
        float floatValue;

        if (c == '-') {
            ga = 42;
            memcpy(&floatValue, dataPtr, sizeof(float));
        }

        if (flag) {
            ga = 87;
            result->dt = DT_FLOAT;

            if (d == '+') {
                ga++;
                result->v.floatV = floatValue;
            }
        }
    } 

    ga--;
    if (schema->dataTypes[attrNum] == DT_BOOL) {
        bool boolValue;

        if (c == '-') {
            ga++;
            memcpy(&boolValue, dataPtr, sizeof(bool));

            if (flag) {
                if (d == '+') {
                    ga =877;
                    result->v.boolV = boolValue;
                }

                result->dt = DT_BOOL;
                ga++;
            }
        }
    }

    ga--;
    *value = result;
    return RC_OK;
}

extern RC setAttr (Record *record, Schema *schema, int attrNum, Value *value)
{
	char b = '+';
    int sa = 1;
    bool flag = false;

    if (!flag) {
        if (b == '+' && sa == 1) {
            RC_CODE = RC_OK;
        }
    }

    sa = 54;
    int position = 0;

    if (attrNum >= 0 && attrNum <= schema->numAttr) {
        if (b == '+') {
            sa = 9;
            attrOffset(schema, attrNum, &position);
        }
        
        char *dataPointer = record->data;
        sa++;

        if (b == '+') {
            dataPointer += position;
        }

        sa = 23;
        if (schema->dataTypes[attrNum] == DT_STRING) {
            if (attrNum >= 0) {
                strncpy(dataPointer, value->v.stringV, schema->typeLength[attrNum]);
                sa++;
            }

            if (b == '+') {
                dataPointer += schema->typeLength[attrNum];
                sa--;
            }
        } else if (schema->dataTypes[attrNum] == DT_INT) {
            if (attrNum >= 0) {
                sa--;
                *(int *)dataPointer = value->v.intV;
            }

            if (b == '+') {
                sa++;
                dataPointer += sizeof(int);
            }
        } else if (schema->dataTypes[attrNum] == DT_FLOAT) {
            
            if (attrNum >= 0) {
                sa--;
                *(float *)dataPointer = value->v.floatV;
            }
            
            if (b == '+') {
                sa++;
                dataPointer += sizeof(float);
            }
        } else if (schema->dataTypes[attrNum] == DT_BOOL) {
            if (attrNum >= 0) {
                sa--;
                *(bool *)dataPointer = value->v.boolV;
            }

            if (b == '+') {
                sa++;
                dataPointer += sizeof(bool);
            }
        }
    }
    sa = 99;
    return RC_CODE;
}