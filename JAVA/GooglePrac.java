	
char duplicateString(String lol)
	{
		 lol = "amer is a fag and gay";
		char x=' ';
		int count = 0;
		
		for(int i = 0; i < lol.length(); i++)
		{
			for(int j = 1; j < lol.length(); j++)
			{
				if(lol.charAt(i) == lol.charAt(j) && i !=j) {
					x = lol.charAt(i);
				}
			}
		}
		return x;
	}
		
	
	static int wordcount(String S)
	{
		int count = 0;
		String [] words = S.split(" ");
		for(int i = 0; i < words.length; i++)
		{
			
			count++;
		}
		return count;
	}
	static int occur(String S, char x)
	{
		int count = 0;
		for(int i = 0; i < S.length(); i++)
		{
			if(S.charAt(i) == x)
			{
				count++;
			}
		}
		return count;
		
		
	}
	
	static String reverse(String S)
	{
		StringBuilder sb = new StringBuilder(S);
		String temp;
		temp= sb.reverse().toString();
		return temp;
		
	}
	
	 String removewhitespaces(String S)
	{
		String S1 = S.replaceAll("//s+","");
		return S1;
		
	}
	 static char nonrepeat(String S)
	 {
		 
		 char t = ' ';
		 for(int i = 0; i <= S.length(); i++)
		 {
			
			if(S.charAt(i) != S.charAt(i+1))
			 {
				 t = S.charAt(i);
				 break;
			 }
			else
			{
				continue;
			}
			 
		 }
		 return t;
	 }
	 
	static String rev(String S)
	 {
		 String temp = " ";
		 for(int i = S.length()-1; i >= 0; i--)
		 {
			 temp+=S.charAt(i);
		 }
		 return temp;
	 }
	
	static boolean onlydig(String S)
	{
		for(char c : S.toCharArray())
		{
			if(!Character.isDigit(c))
			{
				return false;
			}
		}
		return true;
	}
	
	int [] intersection (int [] arr1, int[] arr2, int[] arr3)
	{
		for(int i = 0; i< arr1.length;i++)
		{
			for(int j = 0; j < arr2.length; j++)
			{
				for(int z = 0; z < arr3.length;z++)
				{
					if((arr1[i] == arr2[j]) || arr1[i] == arr3[z] || arr2[j] == arr3[z] )
					{
						
					}
				}
			}
		}
	}
	 
	 
	 
	 
		

}
