public class Test{
	public static void main28(String[] args) {
		int i=0;
		int count=0;
		for(i=1;i<=100;i++) {
			if(i%10==9) {
				count++;
				System.out.println(i);
			}else if(i/10==9) {
				count++;
				System.out.println(i);
			}
		}
		System.out.println(count);
	}
	public static void main27(String[] args) {
		int i=0;
		int sum=0;
		for(i=1;i<=100;i++) {
			sum += 1/i;
			i *= -1;
		}
		System.out.println(sum);
	}
	public static void main26(String[] args) {
		int a=10;
		int b=20;
		int tmp=0;
		int ret1=0;
		int ret2=0;
		while(ret){
			tmp++;
			ret1=a/tmp;
			ret2=b/tmp;
			if(ret1=ret2) {
				System.out.println(tmp);
				break;
			}
		}
	}
	
	public static void main25(String[] args) {
		int i=0;
		int j=0;
		for(i=1;i<=9;i++) {
			for(j=1;j<=i;j++) {
				System.out.printf("%d*%d=%d",i,j,i*j);
			}
		}
	}
	public static void main24(String[] args) {
		int year=0;
		for(year=1000;year<=2000;year++) {
			if((year%100!=0)||(year%4==0&&year%400==0)) {
				System.out.println(year);
			}
		}
	}
	public static void main23(String[] args) {
		int i = 0;
		for(i = 100;i <= 200;i++) {
			for(int j = 2;j < i/2;j++) {
				if(i % j == 0) {
					break;
				}
			}
			System.out.println(i);
			
		}
	}
	public static void main22(String[] args) {
		int num = 30;
		int i = 0;
		for(i = 2;i < num/2;i++){
			if(num%i==0) {
				System.out.println("这个数不是素数。");
				break;
			}else {
				System.out.println("这个数是素数。");
				break;
			}
		}
	}
	public static void main21(String[] args) {
		int age = 23;
		if(age<=18) {
			System.out.println("此人是少年。");
		}else if(age>=19&&age<=28) {
			System.out.println("此人是青年。");
		}else if(age>=29&&age<=55) {
			System.out.println("此人是中年。");
		}else if(age>=56) {
			System.out.println("此人是老年。");
		}
	}
	public static void main2(String[] args) {
		int []array = {9, 15, 30};
		int maxIndex = array[0];
        int minIndex = array[0];
		int i = 0;
        for (i = 0; i < array.length; i++) {
            if(maxIndex < array[i]){
                maxIndex = array[i];
            }
            if(minIndex > array[i]){
                minIndex = array[i];
            }
        }
        System.out.println("maxIndex= "+maxIndex+"\t minIndex= "+minIndex);
	}
	public static void main1(String[] args) {
		int a = 10;
		int b = 20;
		int tmp = 0;
		if(a != b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		System.out.println(a);
		System.out.println(b);
		
	}
	
}
