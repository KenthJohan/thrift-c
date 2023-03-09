#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "thrift.h"

#define ASSERT(c) if (!(c)) __builtin_trap()

#define VALUE_STR_LEN 32



void thrift_onerror(char const * text)
{
    printf("[THRIFT_ERROR] %s\n", text);
}

void thrift_field_print(int32_t id, thrift_type_t type, thrift_value_t value, int32_t indent)
{
	char buf[VALUE_STR_LEN];
	memset(buf, ' ', VALUE_STR_LEN);
	thrift_get_field_str(type, value, buf+indent, VALUE_STR_LEN-indent);
    printf("%02i|%02i|%-6s|", indent, id, thrift_get_type_string(type));
	printf("%-*s |\n", VALUE_STR_LEN, buf);
}

void thrift_parse(uint8_t const * data, int32_t l)
{
    uint8_t const * current = data;
    thrift_type_t type = THRIFT_STRUCT;
    thrift_value_t value;
    int64_t id;
 	thrift_cursor_t cursor = {0};
    cursor.stack_size = 64;
    thrift_cursor_init(&cursor);
	int32_t i = 0;
	printf("|N   |sp|id|type  |value                |\n");
	printf("|----|--|--|------|---------------------|\n");
    while(current)
    {
		printf("|%04i|",i);
        //print_field1(id, type, value, cursor.sp);
        current = thrift_cursor_next(&cursor, current, data+l, &type, &id, &value);
        thrift_field_print(id, type, value, cursor.sp - ((type==THRIFT_STRUCT) || (type==THRIFT_LIST)));
		i++;
    }
}


void thrift_parse_file(char const * filename)
{
    ASSERT(filename);
	FILE * file = fopen(filename, "rb");
    ASSERT(file);
    char par1[4] = {0};
    char par2[4] = {0};
    int32_t l = 0;
    fseek(file, 0, SEEK_SET);
    fread(par1, sizeof(par1), 1, file);
    fseek(file, -8, SEEK_END);
    fread(&l, sizeof(int32_t), 1, file);
    fseek(file, 0, SEEK_SET);
    fread(par2, sizeof(par2), 1, file);
	printf("par1:%.*s\n", 4, par1);
	printf("par2:%.*s\n", 4, par2);
	ASSERT(strncmp(par1, "PAR1", 4) == 0);
	ASSERT(strncmp(par2, "PAR1", 4) == 0);
    fseek(file, -8-l, SEEK_END);
    uint8_t * data = malloc(l);
    fread(data, l, 1, file);
	thrift_parse(data, l);
	if(file) {fclose(file);}
	if(data) {free(data);}
}





int main (int argc, char * argv [])
{
    thrift_api.malloc_ = malloc;
    thrift_api.onerror_ = thrift_onerror;
	thrift_parse_file("userdata1.parquet");
}
