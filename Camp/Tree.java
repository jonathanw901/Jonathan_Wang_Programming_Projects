package camp;

public interface Tree extends DataStructure
{
  public void insert(Comparable x);
  public Comparable lookup(Comparable x);
  public Comparable delete(Comparable x);

  public void print();

  // iterators
  public void reset(int order);
  public boolean hasNext();
  public Comparable getNext();
}
