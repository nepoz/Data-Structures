import java.util.Arrays;
import java.util.Iterator;

@SuppressWarnings("unchecked")
public class DynamicArray <T> implements Iterable<T> {
	
	private T[] rootArray;		//Static Array at base of Dynamic Array
	private int capacity;		//Size of rootArray
	private int length;			//Number of non-null elements in rootArray
	
	public DynamicArray() {
		this(10);
	}
	
	public DynamicArray(int startCapacity){
		
		if (startCapacity > 0) {
			this.capacity = startCapacity;
			this.rootArray = (T[]) new Object[startCapacity];
			this.length = 0;
		}
		else {
			throw new IllegalArgumentException("Capacity must be greater than 0!");
		}
	}
	
	public void append(T newElement) {
		if (this.length < this.capacity) {
			this.rootArray[length] = newElement;
			this.length++;
		}
		else {
			this.increaseSize();
			this.rootArray[length] = newElement;
			this.length++;
		}
	}
	
	public void clear() {
		for (T element : this.rootArray) {element = null;}
		this.capacity = 10;
		this.length = 0;
	}
	
	public void remove (T target) {
		
	}
	
	public void removeAt(int index) {
		if (index < length) {
			//TODO: Valid input; remove index reorder rootArray
			this.rootArray[index] = null;
			length--;
			
			T[] newRoot = (T[]) new Object[capacity];
			
		int i = 0;
		int j = 0;
		while (j < this.length) {
				if (this.rootArray[i] != null) {
					newRoot[j] = rootArray[i];
					i++; j++;
				}
				else {i++;}
			}
		
		this.rootArray = newRoot;
		}
		
		else {
			throw new ArrayIndexOutOfBoundsException();
		}
	}
	
	public void addAt(T newElem, int index) {
		
		if (index < length) {
			//First : Copy elements that come before target to new array
			T[] newRoot = (T[]) new Object[capacity];
			for (int i = 0; i < index ; i++) {
				newRoot[i] = this.rootArray[i];
			}
			
			//Second: Set the desired index to new value
			newRoot[index] = newElem;
			
			//Third: Copy over remaining values
			for (int i = index; i < length ; i++) {
				newRoot[i + 1] = this.rootArray[i];
			}
			
			//Fourth: Update rootArray and its length
			this.rootArray = newRoot;
			this.length++;
		}
		else {
			throw new ArrayIndexOutOfBoundsException();
		}
	}
	
	public boolean has(T target) {
		
		//First case: T implements comparable
		if (target instanceof Comparable) {
			T[] searchArray = (T[]) new Object[capacity];
			searchArray = this.rootArray.clone();
			Arrays.sort(searchArray);
			return (Arrays.binarySearch(searchArray, target) >= 0);
		}
		//Second case: Objects not comparable, linear search
		else {
			for (int i = 0; i < this.length; i++) {
				if (this.rootArray[i].equals(target))
					return true;
			}
			
			return false;
		}
	}
	
	private void increaseSize()
	{
		this.capacity *= 2;
		T[] newRootArray = (T[]) new Object[this.capacity];
		
		int index = 0;
		for (T element : this.rootArray) {
			newRootArray[index++] = element;
		}
		
		this.rootArray = newRootArray;
	}
	
	public T get(int index) {
		return (rootArray[index]);
	}
	
	public void set (T newElem, int index) {
		this.rootArray[index] = newElem;
	}
	
	public int getCapacity() {
		return this.capacity;
	}
	
	public int getLength() {
		return this.length;
	}
	
	public boolean isEmpty(){
		return (this.length == 0);
	}
	
	@Override
	public String toString() {
		T[] printArray = (T[]) new Object[length];
		
		printArray = Arrays.copyOf(rootArray, length);
		
		return Arrays.toString(printArray);
	}
	
	@Override 
	public Iterator <T> iterator () {
	    return new java.util.Iterator <T> () {
	      int index = 0;
	      @Override public boolean hasNext() { return index < length; }
	      @Override public T next() { return rootArray[index++]; }
	      @Override public void remove() { throw new UnsupportedOperationException(); }
	    };
	  }
	
}
