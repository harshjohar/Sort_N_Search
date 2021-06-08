#### Data structures exercise: General Tree

1. Below is the management hierarchy of a company.

    ![ss](management_both.PNG)

Extend print_tree function such that it can print either name tree, designation tree or name and designation tree. As shown below,

   ![](all_trees.png)

Here is how your main function should will look like,
```
if __name__ == '__main__':
    root_node = build_management_tree()
    root_node.print_tree("name") # prints only name hierarchy
    root_node.print_tree("designation") # prints only designation hierarchy
    root_node.print_tree("both") # prints both (name and designation) hierarchy
```

[Solution](https://github.com/Divine275/sort_n_search/blob/master/Intro%20to%20DSA%20in%20python/General_Tree_ex1.py)

2. Build below location tree using **TreeNode** class

    ![](location_trees.png)

Now modify print_tree method to take tree level as input. And that should print tree only upto that level as shown below,

   ![](location_trees_all.png)

[Solution](https://github.com/Divine275/sort_n_search/blob/master/Intro%20to%20DSA%20in%20python/General_tree_ex2.py)
