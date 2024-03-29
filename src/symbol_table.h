#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
 
#define sym_table_t unordered_map<string, tEntry *>

typedef struct table_entry
{
    int size;
    int scope;
    int init; 
    string key;
    string type;
    long offset;
} tEntry;

extern int curr_scope;
extern int num_scopes;
extern stack<int> scope_st;

extern long offset;
extern long struct_offset;

extern string func_args;
extern string func_params;

extern sym_table_t sym_table;
extern unordered_map<int, sym_table_t *> global_scope_table;
extern unordered_map<string, tEntry *> GST;
extern unordered_map<int, string> entry_map;
extern sym_table_t *curr;
extern unordered_map<string, string> FUNC_PARAM;
extern unordered_map<string,int> label_tabel;

extern string struct_name;
extern unordered_map<string, sym_table_t *> struct_symbol_tables;

void init_bool();
void make_symbol_table();
sym_table_t *insert_sym_table(int scope);
tEntry *entry(string key, string type, int init, int size, long offset, int scope);
tEntry* make_struct_entry(string key, string type, long offset, int size);
void insert_entry(string key, string type, int init, int size, long offset, int scope);
void insert_struct_entry(string struct_name, string key, string type, long offset, int size);
tEntry *lookup(stack<int> st, string key);
tEntry *find_struct_entry(string struct_name, string key);
string find_type(stack<int> st, string key);
int getSize(string s);
int struct_size(string s);
void align_struct_offset(int size);
void align_offset(int size);