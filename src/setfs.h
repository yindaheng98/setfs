#define FUSE_USE_VERSION 26
#define PATH_MAX 4096

enum setfs_type
{                 //three types of setfs folder
    subset,       //subset folder
    intersection, //intersection folder
    unionset,     //unionset folder
};

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

struct setfs_attr
{
    enum setfs_type type;
    char *mount_point;     //目录挂载在何处
    union setfs_root root; //被挂载的目录在何处
};

#define SETFS_ATTR ((struct setfs_attr *)fuse_get_context()->private_data)
