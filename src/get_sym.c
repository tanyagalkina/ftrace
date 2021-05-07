/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"

sym_tab_t *create_node(size_t size, unsigned long address, char *name)
{
    sym_tab_t *elem;

    elem = malloc(sizeof(sym_tab_t));
    if (elem == NULL)
        return (NULL);
    elem->address = address;
    elem->name = name;
    elem->size = size;
    elem->next = NULL;
    elem->prev = NULL;
    return (elem);
}

sym_tab_t *add_symbol(sym_tab_t *list, sym_tab_t *new_elem)
{
    sym_tab_t *tmp = list;

    if (list == NULL)
        return (new_elem);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_elem;
    new_elem->prev = tmp;
    return (list);
}

Elf *init_elf(int fd, Elf **e)
{
    if (elf_version(EV_CURRENT) == EV_NONE)
        return (NULL);
    *e = elf_begin(fd, ELF_C_READ, NULL);
    if (*e == NULL) {
        fprintf(stderr, "Error: couldn't retreive elf header.\n");
        return (NULL);
    } else if (elf_kind(*e) != ELF_K_ELF) {
        fprintf(stderr, "File isn't an elf file.\n");
        return (NULL);
    }
    return (*e);
}

sym_tab_t *get_sym_tab(Elf64_Shdr **sym_shdr, Elf_Scn **sym_scn, Elf **e)
{
    Elf_Data *data = elf_getdata(*sym_scn, NULL);
    sym_tab_t *list_sym_tab = NULL;
    int nb_sym = (*sym_shdr)->sh_size / (*sym_shdr)->sh_entsize;
    Elf64_Sym *symtab = (Elf64_Sym *)data->d_buf;
    int st_type = 0;

    for (int i = 0 ; i < nb_sym ; ++i) {
        st_type = ELF64_ST_TYPE(symtab[i].st_info);
        if (st_type == STT_FUNC || st_type == STT_NOTYPE) {
            list_sym_tab = add_symbol(list_sym_tab, \
create_node(symtab[i].st_size, symtab[i].st_value, elf_strptr(*e, (*sym_shdr)->sh_link, symtab[i].st_name)));
            if (list_sym_tab == NULL)
                return (NULL);
        }
    }
    elf_end(e);

    return list_sym_tab;
}

sym_tab_t *get_sym_sec(Elf **e)
{
    Elf64_Shdr *shdr = NULL;
    Elf_Scn *scn = NULL;
    while ((scn = elf_nextscn(*e, scn)) != NULL) {
        shdr = elf64_getshdr(scn);
        if (!shdr)
            return (NULL);
        else if (shdr->sh_type == SHT_SYMTAB)
            return (get_sym_tab(&shdr, &scn, e));
    }
    return (NULL);
}

///returns NULL if there is an error
sym_tab_t *get_symbols(char *path)
{
    Elf *elf = NULL;
    //Elf64_Shdr *shdr = NULL;
    //Elf_Scn *sec = NULL;
    //sym_tab_t *sym = NULL;
    int fd = open(path, O_RDONLY, 0);
    if (fd < 0) {
        fprintf(stderr, "Error: open_failed.\n");
        return (NULL);
    }
    if (init_elf(fd, &elf) == NULL)
        return (NULL);
    if (gelf_getclass(elf) != ELFCLASS64)
        return (NULL);
    return get_sym_sec(&elf);
}