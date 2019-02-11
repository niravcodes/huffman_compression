#ifndef _TREE_H
#define _TREE_H

#define NULL 0

class tree
{
  public:
    class leaf
    {
      private:
        unsigned char data;
        unsigned frequency;
        leaf *left;
        leaf *right;

      public:
        leaf();
        leaf(unsigned char, unsigned, leaf *left, leaf *right);
        bool operator<(const leaf &b);
        bool add_left(leaf *);
        bool add_right(leaf *);
        unsigned char get_data();
        unsigned get_frequency();
    };

    tree();
    tree(leaf *);

  private:
    leaf *root;
};
#endif