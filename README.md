# setfs
A special filesystem, treat a folder as a set.

## Folder is set.
There are two kinds of folder in SetFile: basic folder and computed folder. A basic folder is an independent set, and a computed folder can be an intersection, union set or subset of basic folders or other computed folders.

```c
enum setfs_type {
    subset,
    intersection,
    unionset,
};
```

If a subset folder is initialized as a subset of a superset folder, the subset folder will include all the file in folder B, then you can just delete the items you don't want to include. The delete operation in subset folder won't influence the items in its superset folder. If you want to delete an item in superset folder, you must delete it in all its subset folder before.

```c

//if the folder is subset, then setfs_root is the path of its superset and whiteout folder
struct setfs_root_subset {
    char *superset;
    char *whiteout;
};

//if the folder is intersection or unionset, then setfs_root is a list of basic set folders
struct setfs_root_intersection {
    char* *basicsets;
};
struct setfs_root_unionset {
    char* *basicsets;
};

union setfs_root
{
    struct setfs_root_subset subset;
    struct setfs_root_intersection intersection;
    struct setfs_root_unionset unionset;
};
```

## Item can be folder
Just like most filesystem does, the item in a folder could be files and other folders. In SetFile, beside files, both basic folder and computed folder could be the item in folders.
