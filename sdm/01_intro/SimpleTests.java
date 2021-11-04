public class SimpleTests{

	public static void main(String[] args){
	
		int a = 'x';
		System.out.println(a);
		
		long l = 32768;  // converted in int (no L)
		int cast_test = (short) l;
		System.out.println("Questo è un long: " + l);
		System.out.println("Questo è il cast (short) del long: " + cast_test);
	
	}
	
}
