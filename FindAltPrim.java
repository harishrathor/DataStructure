import java.io.*;

class FindAltPrim{
	public static void main(String args[]){
		FindAltPrim fp=new FindAltPrim();
		fp.findPrimNumbers();
		
	}
	void findPrimNumbers(){
		boolean flag,flag1=true;
			for(int i=2;i<101;i++){
				flag=this.checkPrim(i);
				if(!flag)
					continue ;
				if(flag1){
					System.out.println(i);
					flag1=false;
				}
				else if(!flag1){
					flag1=true;
				}
			}
	}
	
	boolean checkPrim(int number){
	
		for(int j=2;j<number;j++){
			if(number%j==0)
				return false;
		}
		return true;
		
	}
	
}
