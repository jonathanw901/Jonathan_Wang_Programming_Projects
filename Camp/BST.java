package camp;

class BST implements Tree
{
  private class treenode
  {
    public Comparable data;
    public treenode left;
    public treenode right;
  }
  treenode root;
  int count;

  public BST()
    { root=null; count=0; Q=null; }

  public void insert(Comparable x)
  {
    root=inserthelp(root,x);
  }
  private treenode inserthelp(treenode r, Comparable x)
  {
    // base case - r==null
    if(r==null)
    {
      r=new treenode();
      r.data=x;
      r.left=r.right=null;
      count++;
      return r;
    }
    // recursive cases
    if(x.compareTo(r.data)<0) // if x<r.data, insert in left subtree
      { r.left=inserthelp(r.left,x); }
    else // insert in right subtree
      { r.right=inserthelp(r.right,x); }
    return r;
  }

  public Comparable lookup(Comparable x)
  {
    return lookuphelp(root,x);
  }
  private Comparable lookuphelp(treenode r, Comparable x)
  {
    // base cases
    if(r==null) return null; // not here
    if(x.compareTo(r.data)==0) // we found it!
      { return r.data; }
    // recursive cases
    if(x.compareTo(r.data)<0) // look to the left
      { return lookuphelp(r.left,x); }
    else // look to the right
      { return lookuphelp(r.right,x); }
  }

  private Comparable itemdeleted;
  public Comparable delete(Comparable x)
  {
    itemdeleted=null;
    root=deletehelp(root,x);
    return itemdeleted;
  }
  private treenode deletehelp(treenode r,Comparable x)
  {
    // base cases
    if(r==null) // empty tree - do nothing
      { return r; }
    if(x.compareTo(r.data)==0) // found it - do the deletion
    {
      // 0 children case
      if(r.left==null && r.right==null)
      {
        itemdeleted=r.data;
        count--;
        return null;
      }
      // 1 child case
      if(r.left==null) // we have 1 right child
      {
        itemdeleted=r.data;
        count--;
        return r.right;
      }
      if(r.right==null) // we have 1 left child
      {
        itemdeleted=r.data;
        count--;
        return r.left;
      }
      // 2 children
      // 1. find the inorder successor (is)
      treenode is=r.right;
      treenode isparent=r;
      while(is.left!=null) {isparent=is; is=is.left; }
      // 2. copy over the item
      itemdeleted=r.data;
      count--;
      r.data=is.data;
      // 3. remove the is original
      if(isparent.left==is) // is is a left child
        { isparent.left=is.right; } // promote is's right child
      else // is is a right child
        { isparent.right=is.right; } // promote is's right child
      return r;
    }
    // recursive cases
    if(x.compareTo(r.data)<0) // look to the left
      { r.left=deletehelp(r.left,x); }
    else // look to the right
      { r.right=deletehelp(r.right,x); }
    return r; // no change to the root
  }

  public void print() // prints in order
  {
    printhelp(root);
  }
  private void printhelp(treenode r)
  {
    // base case
    if(r==null) return;
    // recursive case
    printhelp(r.left); // left subtree
    System.out.println(r.data);
    printhelp(r.right); // right subtree
  }

  // iterators
  public static final int PREORDER=0;
  public static final int INORDER=1;
  public static final int POSTORDER=2;
  private Queue Q;

  public void reset(int order)
  {
    if(Q==null) { Q=new QueueLL(); }
    else { Q.makeEmpty(); }
    traversal(root,order); // fill the Q with data
  }

  private void traversal(treenode r, int order)
  {
    if(r==null) { return; }
    if(order==PREORDER) { Q.enqueue(r.data); }
    traversal(r.left,order);
    if(order==INORDER) { Q.enqueue(r.data); }
    traversal(r.right,order);
    if(order==POSTORDER) { Q.enqueue(r.data); }
  }

  public boolean hasNext() { return !Q.isEmpty(); }
  public Comparable getNext() { return (Comparable)Q.dequeue(); }

  public int size() { return count; }
  public void makeEmpty()
    { root=null; count=0; }
  public boolean isEmpty() { return count<=0; }
  public boolean isFull() { return false; }
}
