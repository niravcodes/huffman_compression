#ifndef _TREE_H
#define _TREE_H

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
        bool operator<(const leaf &b);
        bool add_left(leaf);
        bool add_right(leaf);
        unsigned char get_data();
        unsigned get_frequency();
    };

  private:
    leaf root;
};
#endif