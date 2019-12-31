# binary-list
A doubly-linked binary tree (with a pointer to 'left', 'right' and 'prev').

How to use direction strings

When using certain functions, such as b\_list\_seek, it is necessary to provide
a direction string. For example, consider the following binary tree:

(B\_NODE\_T has been set to 'float', and the head of the tree is 'head')
                  "ll": 1.1
                 /
         "l": 1.0
        /        \ 
 "": 0.0          "lr": 1.2
        \
         \          "rl": 2.1
          \        /
           "r": 2.0
                   \
                    "rr": 2.2

The strings at each node show the required direction string.
For example,'b\_list\_seek(head, "")' returns a pointer to the head of the
tree.
