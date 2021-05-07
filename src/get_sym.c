/*
** EPITECH PROJECT, 2020
** PSU, instr
** File description:
** src
*/

#include "../include/strace.h"
#include <libelf.h>

Elf *init_elf(int fd, Elf **e)
{
    if (elf_version(EV_CURRENT) == EV_NONE) {
        perror("elf version");
        return (NULL);
    }

    *e = elf_begin(fd, ELF_C_READ, NULL);

    if (*e == NULL) {
        perror("elf header");
        return (NULL);
    }

    if (elf_kind(*e) != ELF_K_ELF) {
        perror("elf kind");
        return (NULL);
    }
    return (*e);
}

sym_tab_t *get_sym_tab(Elf64_Shdr *sym_shdr, Elf_Scn *sym_scn, Elf **e)
{
    sym_tab_t *list_sym_tab = NULL;
    Elf_Data *data = elf_getdata(sym_scn, NULL);
    Elf64_Sym *symtab = (Elf64_Sym *)data->d_buf;
    int entries = sym_shdr->sh_size / sym_shdr->sh_entsize;
    int st_type = 0;

    for (int i = 0 ; i < entries ; ++i) {
        st_type = ELF64_ST_TYPE(symtab[i].st_info);
        if (st_type == STT_FUNC || st_type == STT_NOTYPE) {
            sym_tab_t *node = create_node(symtab[i], sym_shdr->sh_link, *e);
            if (node == NULL)
                return NULL;
            list_sym_tab = add_node(list_sym_tab, node);
            if (list_sym_tab == NULL)
                return (NULL);
        }
    }
    elf_end(*e);
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
            return (get_sym_tab(shdr, scn, e));
    }
    return (NULL);
}

sym_tab_t *get_symbols(char *path)
{
    Elf *elf = NULL;

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
