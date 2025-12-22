#include "push_swap.h"
int main(int argc, char* argv[])
{
    t_stack SA;
    t_stack SB;
    if(argc < 2)
        return (0);
    init_stack(&SA);
    init_stack(&SB);
    if (!parse_input(argc, argv, &SA))
        //error_exit();
        printf("error\n");
    else
        printf("success\n");
    // if (is_sorted(&SA))
    //     do_exit();
    // if (SA.size <= 5)
    //     sort_small(&SA);
    // else
    //     sort_chunk(&SA);
    // free_all(&SA, &SB);
return (0);
}