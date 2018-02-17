#pragma once

typedef struct linked_list_s linked_list;
typedef struct list_item_s list_item;

typedef struct titledb_cia_info_s {
    bool exists;

    u32 id;
    char updatedAt[32];
    char version[32];
    u64 size;
    u64 titleId;

    bool installed;
    u16 installedVersion;
} titledb_cia_info;

typedef struct titledb_smdh_info_s {
    bool exists;

    u32 id;
} titledb_smdh_info;

typedef struct titledb_tdsx_info_s {
    bool exists;

    u32 id;
    char updatedAt[32];
    char version[32];
    u64 size;
    titledb_smdh_info smdh;

    bool installed;
} titledb_tdsx_info;

typedef struct titledb_info_s {
    u32 id;
    char category[64];
    char headline[512];
    titledb_cia_info cia;
    titledb_tdsx_info tdsx;

    meta_info meta;
} titledb_info;

typedef struct populate_titledb_data_s {
    linked_list* items;

    volatile bool itemsListed;
    volatile bool finished;
    Result result;
    Handle cancelEvent;
    Handle resumeEvent;
} populate_titledb_data;

void task_populate_titledb_update_status(list_item* item);
void task_free_titledb(list_item* item);
void task_clear_titledb(linked_list* items);
Result task_populate_titledb(populate_titledb_data* data);