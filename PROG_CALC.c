#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
#define ERR1 954647751435555983.5744733
#define ERR2 8546477514353575467.71413564
#define TOLMIN 0.0000001
//Вычисление квадратного корня
double f_sqrt (double arg, double toler)
{
	double res = 1, gain = 1, inc;
	if(arg == 0)  return 0;
	if(arg < 1) 
	{
	   gain = -1;
	   arg = 1 / arg;
    }
	if(arg < 0) return ERR1;
 	while(arg >= 100)
	{
		arg /= 100;
		res *= 10;
	}
		while(arg >= 4)
	{
		arg /= 4;
		res *= 2;
	}
	while(arg >= 1.44)
	{
		arg /= 1.44;
		res *= 1.2;
	}
	inc = 1.1;
	double delX = 0;
	while (2 == 2)
	{
		delX = arg - (inc * inc);
		delX /= 2;
		inc += delX;
		if((delX < toler) && (delX > (-toler)))
		    break;
	}
	res = res * inc;
	if(gain == -1) 
	  res = 1 / res;
	return(res);  
}
//Натуральный логарифм
double f_ln (double arg, double toler)
{
	double gain = 1,res = 0, con100 = 4.60517019, con4 = 1.38629436, 
	con105 = 0.405465108, con102 = 0.182321557;
	if(arg <= 0) 
	   return (ERR1);
	if(arg < 1)
	{
	   gain = -1;
	   arg = 1 / arg;	
	} 
	while (arg >= 100)  
	{
		arg /= 100;
		res += con100;
	}
	while (arg >= 4)  
	{
		arg /= 4;
		res += con4;
	}
		while (arg >= 1.5)  
	{
		arg /= 1.5;
		res += con105;
	}
	while (arg >= 1.1)  
	{
		arg /= 1.2;
		res += con102;
	}
	arg -= 1;
	double i = 1, pow = -arg, num = arg, buff;
	while(4 == 4)
	{		
		buff = num / i;
		res += buff;
		if((buff < toler) && (buff > (-toler)))
		    return(res * gain);
		num *= pow;
		i += 1;    
	}
}
//Экспонента
double f_exp (double arg, double toler)
{
	double res = 1, sum = 0, gain;
    double con20 = 485165195, con5 = 148.413159, con1 = 2.71828183, con02 = 1.22140276;    
	if(arg < -43)
	   return 0;
	if(arg < 0)	
    {
    	gain = -1;
    	arg *= -1;
	}else	
	gain = 1;
	if(arg > 43)
	    return ERR1;
	while(arg >= 20)
	{
		arg -= 20;
		res *= con20;
	}
	while(arg > 5)
	{
		arg -= 5;
		res *= con5;
	}
	while(arg >= 1)
	{
		arg -= 1;
		res *= con1;
	}
	while(arg > 0.1)
	{
		arg -= 0.2;
		res *= con02;
	}
	double i = 1;
	double con = 1;
	while(1 == 1)
	{
		sum += con;
		if((con < toler) && (con > (-toler)))
		    break;
		con = con * arg / i;
		i += 1;
	}
	res = res * sum;
	if(gain == -1)
	   res = 1 / res;
	return (res);   
}
//Синус
double f_sin(double arg, double toler)
{
	int buf1;
	double buf2;
	buf2 = arg / (2 * PI);
	buf1 = buf2;
	buf2 = buf1;
	arg = arg - (buf2 * 2 * PI);     
	while(arg < -PI) arg += (2 * PI);
	while(arg > PI) arg -= (2 * PI);
	if(arg > (PI * 0.5)) arg = PI - arg;
	if(arg < -(PI * 0.5)) arg = -PI - arg;
	double i = 1,fact = 1;
	double inc = -1;
	double con = arg;
	double sum = 0, pow;
	pow = -1 * arg * arg;
	while(1 == 1)
	{
		sum += con;
		if((con < toler) && (con > (-toler)))
		    return (sum);
		fact = (i + 1) * (i + 2);
		con *= pow;
		con /= fact;
		i += 2;
	}
}
double f_cos(double arg, double toler)
{
	int buf1;
	double buf2;
	buf2 = arg / (2 * PI);
	buf1 = buf2;
	buf2 = buf1;
	arg = arg - (buf2 * 2 * PI); 
	double gain;
	while(arg < 0) arg += (2 * PI);
	while(arg > (2 * PI)) arg -= (2 * PI);
	if(arg > PI) arg = (2 * PI) - arg;
	if(arg > (PI / 2)) 
	{
	   arg = PI - arg;
	   gain = -1;
    }else
    gain = 1;
	double i = 2,fact = 2;
	double inc = -1;
	double con = 1;
	double sum = 1, pow;
	pow = arg * arg;
	while(1 == 1)
	{
		con = con * inc * pow / fact;
		sum += con;
		if((con < toler) && (con > (-toler)))
		{
		  sum = sum * gain;	
		  return (sum);
	    }
		fact =  (i + 1) * (i + 2);
		i += 2;
	}
}
//Вычисление арксинуса
double f_asin(double arg, double toler)
{
	float gain, cos_v, sin_v, angle, delA;
	if((arg < -1) || (arg > 1))
       return ERR1;
    if(arg < 0) 
	{
	  arg *= -1;	
	  gain = -1;
    }
	else 
	gain = 1;
	if(arg < 0.707) 
	{
		angle = (PI / 4)  * arg / 0.707;
		while (1 == 1)
		{
			sin_v = f_sin(angle, toler);
			cos_v = 1 - (sin_v * sin_v);
			cos_v = f_sqrt(cos_v,toler);
			delA = (arg - sin_v) / cos_v;
			angle += delA;
			if((delA < toler) && (delA > (-toler)))
			   return (gain * angle);
		}
	}
	else
	{
		arg = f_sqrt((1 - (arg * arg)), toler);
		angle = (PI / 2) - (arg / 0.707);
		while (1 == 1)
		{
			cos_v = f_cos(angle, toler);
			sin_v = 1 - (cos_v * cos_v);
			sin_v = f_sqrt(sin_v,toler);
			delA = (cos_v - arg) / sin_v;
			angle += delA;
			if((delA < toler) && (delA > (-toler)))
			   return (gain * angle);
	    }
    }
}
double f_acos(double arg, double toler)
{
	double res;
		if((arg < -1) || (arg > 1))
       return ERR1;
	res = f_asin(arg, toler);
	res = (PI / 2) - res;
	return (res);
}
double f_atg(double arg, double toler)
{
	double res, buff;
	buff = f_sqrt((1 + (arg * arg)), toler);
	arg = arg / buff;	
	res = f_asin(arg, toler);
	return (res);
}
double f_actg(double arg, double toler)
{
	double res, buff;
	buff = f_sqrt((1 + (arg * arg)), toler);
	buff = 1 / buff;
	if(arg < 0) 
	  buff *= -1;	
	res = f_asin(buff, toler);
	return (res);
}
double f_log(double arg1, double arg2, double toler)
{
	if((arg1 <= 0) || (arg2 <= 0) || (arg1 == 1) )
	  return ERR1;
	double res, ln1, ln2;
	ln1 = f_ln(arg1, toler);
	ln2 = f_ln(arg2, toler);
	res = ln2 / ln1;
	return (res); 
}
double f_tg(double arg, double toler)
{
	int buf1;
	double buf2;
	buf2 = arg / (2 * PI);
	buf1 = buf2;
	buf2 = buf1;
	arg = arg - (buf2 * 2 * PI); 
	while (arg < -(PI / 2)) arg += PI;
	while (arg > (PI / 2)) arg -= PI;
	double res, sin_v, cos_v;
    sin_v = f_sin(arg, toler);
    cos_v = f_sqrt((1 - (sin_v * sin_v)), toler);
    if(cos_v == 1)
      return ERR1;
	res = sin_v / cos_v; 
	return (res); 
}
double f_ctg(double arg, double toler)
{
	int buf1;
	double buf2;
	buf2 = arg / (2 * PI);
	buf1 = buf2;
	buf2 = buf1;
	arg = arg - (buf2 * 2 * PI); 
	while (arg < -(PI / 2)) arg += PI;
	while (arg > (PI / 2)) arg -= PI;
	double res, sin_v, cos_v;
    sin_v = f_sin(arg, toler);
    if(sin_v == 0)
      return (ERR1);
    cos_v = f_sqrt((1 - (sin_v * sin_v)), toler);
	res = cos_v / sin_v; 
	return (res); 
}
double f_ch(double arg, double toler)
{
	double res, ex, buff;
    ex = f_exp(arg, toler);
    buff = 1 / ex;
    res = ex + buff;
    res /= 2;
	return (res); 
}
double f_sh(double arg, double toler)
{
	double res, ex, buff;
    ex = f_exp(arg, toler);
    if((ex == ERR1) || (ex == 0))
       return ERR1;  
    buff = 1 / ex;
    res = ex - buff;
    res /= 2;
	return (res); 
}
double f_th(double arg, double toler)
{
	double res, ex, buff;
	if(arg > 11 || (arg < -11))
	   return 1;
    ex = f_exp(arg, toler);
    buff = 1 / ex;
    res = ex - buff;
    ex = ex + buff;
    res = res / ex;
	return (res); 
}
double f_cth(double arg, double toler)
{
	double res, ex, buff;
	if(arg > 11 || (arg < -11))
	   return 1;
	if(arg == 0)
	   return (ERR1);
    ex = f_exp(arg, toler);
    buff = 1 / ex;
    res = ex - buff;
    ex = ex + buff;
    res = ex / buff;
	return (res); 
}
double f_pow(double arg1, double arg2, double toler)
{
	if(arg1 < 0)
	    return ERR1;
	if(arg1 == 1)
	    return 1;    
	double res, ln_x, ex;
	ln_x = f_ln(arg1, toler);
	ex = arg2 * ln_x;
	if(ex > 43)
	  return ERR2;
	res = f_exp(ex, toler);
	return (res);
}
double f_ach(double arg, double toler)
{
	double res, ex, buff;
	if(arg < 1)
	   return (ERR1);   
	buff = f_sqrt((arg * arg - 1), toler);   
    ex = arg + buff;
    res = f_ln(ex,toler);
	return (res); 
}
double f_ash(double arg, double toler)
{
	double res, ex, buff;
	buff = f_sqrt((arg * arg + 1), toler);   
    ex = arg + buff;
    res = f_ln(ex,toler);
	return (res); 
}
double f_acth(double arg, double toler)
{
	double res, ex, buff;
	if((arg <= 1) && (arg >= -1))
	   return(ERR1);
	buff = (arg + 1) / (arg - 1);
    res = f_ln(buff,toler);
    res /= 2;
	return (res); 
}
double f_ath(double arg, double toler)
{
	double res, ex, buff;
	if((arg > 1) || (arg < -1))
	   return(ERR1);
	buff = (arg + 1) / (1 - arg);   
    res = f_ln(buff,toler);
    res /= 2;
	return (res); 
}
// Функция, получающая в качестве входного аргумента численный идентификатор вычисляемой функции, 
// и ее аргументы
double call_f(int name,double arg1, double arg2, double toler,FILE * f3)
{ 
	double res;
	if(name == 190)  
	{
       res = f_ach(arg1, toler);
       if(res == ERR1)
         	fprintf(f3,"Input of 'ach' supposed to be '>= 1'\n");
	   return(res);
    }
	if(name == 191)  
	{
       res = f_acos(arg1, toler);
       if(res == ERR1)
          fprintf(f3,"Arg of 'acos' to be located in [-1....1]\n");
	   return(res);
    }
	 if(name == 192)  
	{
       res = f_actg(arg1, toler);
       if (res == ERR1)
          fprintf(f3,"Was founded: arg of 'ctg' = 0. No way to solve\n");
	   return(res);
    }
    if(name == 193)  
	{
       res = f_acth(arg1, toler);
       if(res == ERR1)
           fprintf(f3,"Func 'acth' must be with arg '> 1' or '< 1'\n");
	   return(res);
    }
    if(name == 194)  
	{
       res = f_ash(arg1, toler);
	   return(res);
    }
	if(name == 195)  
	{
       res = f_asin(arg1, toler);
       if(res == ERR1)
          fprintf(f3,"Arg of 'asin' to be located in [-1....1]\n");
	   return(res);
    }
    if(name == 196)  
	{
       res = f_atg(arg1, toler);
	   return(res);
    }
    if(name == 197)  
	{
       res = f_ath(arg1, toler);
       if(res == ERR1)
          fprintf(f3,"Arg of ath to be in (-1....+1)\n");
	   return(res);
    }
    if(name == 198)  
	{
       res = f_ch(arg1, toler);
	   return(res);
    }
	if(name == 199)  
	{
       res = f_cos(arg1, toler);
	   return(res);
    }
    if(name == 200)  
	{
       res = f_ctg(arg1, toler);
	   return(res);
    }
    if(name == 201)  
	{
       res = f_cth(arg1, toler);
	   return(res);
    }
    if(name == 202)  
	{
       res = f_exp(arg1, toler);
       if(res == ERR1)
       fprintf(f3,"Arg of 'exp' expected to be '<=43'\n");
	   return(res);
    }
    if(name == 203)  
	{
       res = f_ln(arg1, toler);
       if(res == ERR1)
          fprintf(f3,"Arg of 'ln' expected to be > 0\n");
	   return(res);
    }
      if(name == 204)  
	{
       res = f_log(arg1, arg2, toler);
       if(res == ERR1)
          fprintf(f3, "Unexpected arg value in 'log'\n");
	   return(res);
    }
    if(name == 205)  
	{
       res = f_pow(arg1,arg2, toler);
       if(res == ERR1)
         fprintf(f3, "First arg in 'pow' must be > 0\n");
       if(res == ERR2)  
         fprintf(f3, "Pow arguments bigger than expected\n");
	   return(res);
    }
    if(name == 206)  
	{
       res = f_sh(arg1, toler);
       if(res == ERR1)
	       fprintf(f3,"Arg of 'sh' is out of right values\n");
	   return(res);
    }
	if(name == 207) 
	{
       res = f_sin(arg1, toler);
	   return(res);
    }
    if(name == 208) 
	{
       res = f_sqrt(arg1, toler);
       if (res == ERR1)
         fprintf(f3,"Arg of 'sqrt' must be > 0\n");
	   return(res);
    }
    if(name == 209)  
	{
       res = f_tg(arg1, toler);
       if(res == ERR1)
         fprintf(f3, "Solving of 'tg' comes to inf\n");
	   return(res);
    }
    if(name == 210)  
	{
       res = f_th(arg1, toler);
	   return(res);
    }
}
// Функция для проверки синтаксиса, выдает ошибку, если введенное выражение содержит неверный символ или 
// неправильную комбинацию скобок/знаков
int control (int res,int stat)
{
	if(res == 7)	return 3;
	if(stat == 2)
	{
		if((res == 1) || (res == 4) || (res == 3)) return -1;
		if((res == 5) || (res == 6)) return 3;
		if(res == 2) return 2;
	}
	if(stat == 3)
	{
		if(res == 1) return 5;
		if(res == 4) return 3;
		if(res == 3) return 2;
		if(res == 5) return 4;
		if((res == 6) || (res == 2)) return -1;
	}
	if(stat == 4)
	{
		if((res == 5) || (res == 6) || (res == 2)) return -1;
		if(res == 1) return 5;
		if(res == 3) return 2;
		if(res == 4) return 3;
	}
		if(stat == 5)
	{
		if((res == 6) || (res == 2)) return -1;
		if(res == 1) return 5;
		if(res == 4) return 3;
		if(res == 3) return 2;
		if(res == 5) return 3;
	}
}
// Эта функция опознает, что перед ней - число, функция, или операнд
int what_is (int e,int r)
{
	if((e > 299) && (e < 350))
	{
		if(e > r) return 1;
		if(e == r) return 2;
	}
	if((e > 129) && (e < 161))
        return 3;
    if((e > 189) && (e < 221))
        return 4;
    if((e == '-') || (e == '+'))
        return 5;
    if((e == '/') || (e == '*'))
        return 6; 
	if(e == 500)
        return 7; 	
	return -1;	   
}
// Функция сравнения строк
int str_ident(int * u1, int * u2)
{
    int i3;
    int i = 0;
	for(i3 = 0;i3 < 30;i3 += 1)
	{
	if(u1[i] > u2[i])
	   return (1);
	if(u1[i] < u2[i])
	   return (-1);
	if(u1[i] == 0)
	   return (0); 
	i += 1;  
    }
}
// Печатает строку
write_str (int * u3, FILE * f)
{
    int i2 = 0;		
	while(u3[i2] != 0)
	{ 
	    fprintf(f,"%c",u3[i2]);
		i2 += 1;
	}
}	
// Проверка, является ли символ арифметическим операндом
int is_oper(int u2)
{
	if(((u2 > 39) && (u2 < 44)) || (u2 == 45) || (u2 == 47) || (u2 == '_'))
	  return(1);
	return(0);
}
is_num(int * u2, int u1)
{
	if((u2[u1] > 48) && (u2[u1] < 58))
	  return(10);
	if(u2[u1] == '0')  
	  {
	  	if(u2[u1+1] == 'b') 
	  	  return(2); 
	  	if(u2[u1+1] == 'o') 
	  	  return(8); 
	    if(u2[u1+1] == 'x') 
	  	  return(16);
		return(10); 			 
	  }
	return(0);
}
// Далее следуют функции проверки системы исчисления
check_16(int  u1)
{
	if((u1 > 47) && (u1 < 58))
	   return(u1 - 48);
	if((u1 > 64) && (u1 < 71))
	   return(u1 - 55);
	if (u1 == '.') 
	  return(-2);
	if(((is_oper(u1) == 0) || (u1 == '(') || (u1 == '_')) && (u1 != '='))  
	   return (-3);
	return(-1);
}
check_10(int u1)
{
	if((u1 > 47) && (u1 < 58))
	   return(u1 - 48);
	if (u1 == '.') 
	return(-2);
	if(((is_oper(u1) == 0) || (u1 == '(') || (u1 == '_')) && (u1 != '='))  
	   return (-3);
	return(-1);
}
check_8(int u1)
{
	if((u1 > 47) && (u1 < 56))
	   return(u1 - 48);
	if (u1 == '.') 
	  return(-2);
	if(((is_oper(u1) == 0) || (u1 == '(') || (u1 == '_')) && (u1 != '='))  
	   return (-3);
	return(-1);
}
check_2(int  u1)
{
	if((u1 > 47) && (u1 < 50))
	   return(u1 - 48);
	if (u1 == '.') 
	  return(-2);
	if(((is_oper(u1) == 0) || (u1 == '(') || (u1 == '_')) && (u1 != '='))  
	   return (-3);
	return(-1);
}
// Начало программы
void main()
{
    FILE *f, * f2 ,*f3;
	// Открытие файла с выражениями
	f = fopen("input.txt","r+");
	if(f == NULL)
	  {
	  	printf("ERROR 201: unable to open file 'input.txt'\n");
	  	goto crashed;
	  }
	// Файл со списком функций 
	  	f2 = fopen("functions.txt","r+");
	if(f2 == NULL)
	  {
	  	printf("ERROR 201: file 'functions.txt' wan not found\n");
	  	goto crashed;
	  }
	 //Создание файла для записи  
	f3 = fopen("outputs.txt","w");
	double nums[30], gain, result , count ,toler;
	toler = 0.0000001;
	double power,sum,tmp_fl, arg1, arg2;
	int str_dr[300],str_cl[100],tmp,i5,tmp1,i2, first_p, remind, tmp2;
	fseek(f,0,SEEK_END);  
    fprintf(f,"\nQ");
    fseek(f,0,SEEK_SET);
    //Структура, в которой сохранены названия и численные обозначения функций 
	  struct func
	  {
	  	  int name[10];
	  	  int arg;
	  	  int design;
	  };
	  struct func * first, * tmp_3;
	  first = (struct func *)malloc(23 * sizeof(struct func));
	  tmp_3 = (struct func *)malloc(sizeof(struct func));
	//Запись списка функций из файла "functions.txt" в структуру
	  for (i5 = 1;i5 < 22;i5 += 1)
    {
        tmp1 = ' ';
		while((tmp1 == ' ') || (tmp1 == '\n')) fscanf(f2,"%c",&tmp1);
		i2 = 0;
		while(tmp1 != ' ')
		  {
		  	(first + i5)->name[i2] = tmp1;
		  	i2 += 1;
		  	fscanf(f2,"%c",&tmp1);
		  }
    	(first + i5)->name[i2] = 0;
    	int i3 = 0;
    	int tmp = 4;
    	while(tmp != 0)
    	{
    	   tmp = (first + i5)->name[i3];
		   i3++;
		}
    	fscanf(f2,"%d",&((first + i5)->arg));
    	fscanf(f2,"%d",&((first + i5)->design));
    }
	//Вывод списка команд в консоль
    printf("			Welcome to the engineering calc!\n");
    printf("Program was created for every kind of calculation.");
    printf("To use the program,\n follow the instructions below:\n");
    printf("1. Put your math expessions into file 'input.txt'\n");
    printf("2. Arter every expression expected character '='\n");
    printf("3. In the end of expression list push 'Q'\n");
    printf("4. Locate 'cursor' at start of file\n");
    printf("5. Check 'outputs.txt' in project folder\n");
    printf("Program while calculating uses 'tolerance interval'.");
    printf("This is value that includes max_error\n of calculating. It is possible to change it for value you want\n");
    printf("You may write it like example: '2e-6' as '2 6', '3.743e-8' as '3743 11' etc\n");
	// Цикл для замены значения максимальной погрешности
    while(3)
    {
        printf("Current tolerance: %0.7f\n", toler);
        printf("     What do you want to do?\n");
        printf("1 - Start calculations 2 - Change tolerance\n");
        scanf("%d",&tmp);
        if(tmp == 1)
           goto start_calc;
        if(tmp == 2)
		{
		   double toln;
		   int wr,wr1;
		   printf("Put in new value:  \n");
		   scanf("%d",&wr);
		   scanf("%d",&wr1);
		   if((wr <= 0) || (wr1 <= 0)) 
		   {
		   	  printf("Unexpected input. Use values > 0\n");
		   	  goto end2;
		   }
		    toln = wr;
		   	for(i2 = 4;i2 < wr1;wr1 -= 4)
			   toln /= 10000;
			for(i2 = 0;i2 < wr1;wr1 -= 1)
			   toln /= 10;
			if((toln > 0.1) || (toln < TOLMIN))
			{
				printf("Value of tolerance must be in [1e-7.....0.1]\n");
				goto end2;
	        }    
			toler = toln;       	     	
		} 
		end2:;
    }
  start_calc:;    
  while (1 == 1)  
  { 
	int ins = 300;
    int num = 130, tmp7;
	int coun_num = 1;
	tmp = '0';
	int i = 1;
    tmp7 = 28;
	i = 1;
	//Считывание строки выражения из файла "input.txt"
	while(tmp7  != '=')
	{
		if(tmp7 == 'Q')
		   goto end;
		fscanf(f,"%c",&tmp7);
		if((tmp7 != ' ') && (tmp7 != '\n')) 
		{
		   str_dr[i] = tmp7;
		   i += 1;
	    }
	}
	tmp7 = 23;
	i = 1;
	while(str_dr[i] != '=')
	{
		fprintf(f3,"%c",str_dr[i]);
		i += 1;
	}
	fprintf(f3,"%c\n",str_dr[i]);
	tmp = str_dr[1];
	str_cl[1] = 300;
	int coun_cl = 2;
	int coun_dr = 1;
	int oper;
	// Замена символов из введенной строки на числа, операнды и функции
	while(tmp != '=')
	{
	   start:;
	   if(is_oper(tmp) == 1)
	      {
	      	 if(tmp == '(')
	      	   {
	      	   	  ins += 1;
	      	   	  tmp = ins;
			   }
			  if(tmp == ')')
	      	   {
	      	   	  tmp = ins;
	      	   	  ins -= 1;
			   } 
			   str_cl[coun_cl] = tmp;
			   coun_cl += 1;
			   coun_dr += 1;
			   tmp = str_dr[coun_dr];
		  }else
		  {
			 int res_num = is_num(str_dr,coun_dr);
			 if(res_num == 16)
		  	 {
		  	 	coun_dr += 2;
		  	 	sum = 0;
		  	 	power = 16;
		  	 	  while(1 == 1)
		  	 	  {
					tmp_fl = check_16(str_dr[coun_dr]);
		  	 	    if(tmp_fl == -1)
		  	 	    {
		  	 	 	   nums[num - 130] = sum;
		  	 	 	   str_cl[coun_cl] = num;
		  	 	 	   coun_cl += 1;  
		  	 	 	   num += 1;
		  	 	 	   tmp = str_dr[coun_dr];
		  	 	 	   goto start;
				    }
				   if(tmp_fl == -3)
		  	 	    {
		  	 	 	   fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	    goto crashed;
				    }    
				   if(tmp_fl == -2)
		  	 	    {
		  	 	 	   coun_dr += 1;
		  	 	 	   power = 0.0625;
		  	 	 	   while(2 == 2)
		  	 	 	   {
						   tmp_fl = check_16(str_dr[coun_dr]);
						    if(tmp_fl == -1)
		  	 	              {
		  	 	 	             nums[num - 130] = sum;
		  	 	 	             str_cl[coun_cl] = num;
		  	 	 	             coun_cl += 1;
		  	 	 	             num += 1;
		  	 	 	             tmp = str_dr[coun_dr];
		  	 	 	             goto start;
				              }
				             if((tmp_fl == -2)  || (tmp_fl == -3))
		  	 	              {
		  	 	 	            fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	            goto crashed;
				              } 
							sum += tmp_fl * power;
							coun_dr++;
							power /= 16;  
				        }  
			        }
			        sum *= power;
			        sum += tmp_fl;
			        coun_dr++;	        
		        }
	   	   } 
	   	   if(res_num == 10)
		  	 {
				sum = 0;
		  	 	power = 10;
		  	 	  while(1 == 1)
		  	 	  {
					tmp_fl = check_10(str_dr[coun_dr]);
		  	 	    if(tmp_fl == -1)
		  	 	    {
		  	 	 	   nums[num - 130] = sum;
		  	 	 	   str_cl[coun_cl] = num;
		  	 	 	   coun_cl += 1;  
		  	 	 	   num += 1;
		  	 	 	   tmp = str_dr[coun_dr];
		  	 	 	   goto start;
				    }
				    if(tmp_fl == -3)
		  	 	        {
		  	 	 	        fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	        goto crashed;
				        } 
				   if(tmp_fl == -2)
		  	 	    {
		  	 	 	   coun_dr += 1;
		  	 	 	   power = 0.1;
		  	 	 	   while(2 == 2)
		  	 	 	   {
						   tmp_fl = check_10(str_dr[coun_dr]);
						     if((tmp_fl == -2)  || (tmp_fl == -3))
		  	 	              {
		  	 	 	            fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	            goto crashed;
				              } 
							if(tmp_fl == -1)
		  	 	              {
		  	 	 	             nums[num - 130] = sum;
		  	 	 	             str_cl[coun_cl] = num;
		  	 	 	             coun_cl += 1;
		  	 	 	             num += 1;
		  	 	 	             tmp = str_dr[coun_dr];
		  	 	 	             goto start;
				              }
							sum += tmp_fl * power;
							coun_dr++;
							power /= 10;  
				        }  
			        }
			        sum *= power;
			        sum += tmp_fl;
			        coun_dr++;	        
		        }
	   	   } 
	   	   if(res_num == 8)
		  	 {
		  	 	coun_dr += 2;
				sum = 0;
		  	 	power = 8;
		  	 	  while(1 == 1)
		  	 	  {
					tmp_fl = check_8(str_dr[coun_dr]);
		  	 	     if(tmp_fl == -3)
		  	 	        {
		  	 	 	        fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	        goto crashed;
				        } 
					if(tmp_fl == -1)
		  	 	    {
		  	 	 	   nums[num - 130] = sum;
		  	 	 	   str_cl[coun_cl] = num;
		  	 	 	   coun_cl += 1;  
		  	 	 	   num += 1;
		  	 	 	   tmp = str_dr[coun_dr];
		  	 	 	   goto start;
				    }
				   if(tmp_fl == -2)
		  	 	    {
		  	 	 	   coun_dr += 1;
		  	 	 	   power = 0.125;
		  	 	 	   while(2 == 2)
		  	 	 	   {
						   tmp_fl = check_8(str_dr[coun_dr]);
						    if((tmp_fl == -2)  || (tmp_fl == -3))
		  	 	              {
		  	 	 	            fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	            goto crashed;
				              } 
							if(tmp_fl == -1)
		  	 	              {
		  	 	 	             nums[num - 130] = sum;
		  	 	 	             str_cl[coun_cl] = num;
		  	 	 	             coun_cl += 1;
		  	 	 	             num += 1;
		  	 	 	             tmp = str_dr[coun_dr];
		  	 	 	             goto start;
				              }
							sum += tmp_fl * power;
							coun_dr++;
							power /= 8;  
				        }  
			        }
			        sum *= power;
			        sum += tmp_fl;
			        coun_dr++;	        
		        }
	   	   }
		   if(res_num == 2)
		  	 {
				coun_dr += 2;
				sum = 0;
		  	 	power = 2;
		  	 	  while(1 == 1)
		  	 	  {
					tmp_fl = check_2(str_dr[coun_dr]);
		  	 	    if(tmp_fl == -3)
		  	 	        {
		  	 	 	       fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	       goto crashed;
				        } 
					if(tmp_fl == -1)
		  	 	    {
		  	 	 	   nums[num - 130] = sum;
		  	 	 	   str_cl[coun_cl] = num;
		  	 	 	   coun_cl += 1;  
		  	 	 	   num += 1;
		  	 	 	   tmp = str_dr[coun_dr];
		  	 	 	   goto start;
				    }
				   if(tmp_fl == -2)
		  	 	    {
		  	 	 	   coun_dr += 1;
		  	 	 	   power = 0.5;
		  	 	 	   while(2 == 2)
		  	 	 	   {
						    tmp_fl = check_2(str_dr[coun_dr]);
						    if((tmp_fl == -2)  || (tmp_fl == -3))
		  	 	              {
		  	 	 	            fprintf(f3,"ERROR 202: Unexpected character '%c' at %d position\n",str_dr[coun_dr],coun_dr);
		  	 	 	            goto crashed;
				              } 
							if(tmp_fl == -1)
		  	 	              {
		  	 	 	             nums[num - 130] = sum;
		  	 	 	             str_cl[coun_cl] = num;
		  	 	 	             coun_cl += 1;
		  	 	 	             num += 1;
		  	 	 	             tmp = str_dr[coun_dr];
		  	 	 	             goto start;
				              } 
							sum += tmp_fl * power;
							coun_dr++;
							power /= 2;  
				        }  
			        }
			        sum *= power;
			        sum += tmp_fl;
			        coun_dr++;	        
		        }
	   	   }
		   if(res_num == 0)	
		   {
			  if(tmp == '=')
			  goto end_check;
			  if(((tmp > 96) && (tmp < 123))  ==  0)
			  {
			  	fprintf(f3,"ERROR 205: Wrong value '%c' at position %d\n",tmp,coun_dr);
			  	goto crashed;
			  }
			  int i4 = 0;
			  int fstr[10],resf;
			  while((tmp > 96) && (tmp < 123)) 
			     {
			     	fstr[i4] = tmp;
			     	tmp = str_dr[++coun_dr];
			     	i4 += 1;
				 }
			  fstr[i4] = 0;
			  int st,fn,mid,res;
	          st = 1;
             fn = 21;
			 // Введена функция, поиск ее в списке стандартных функций для
			 // нахождения ее индивидуального номера
			 // Поиск  использует бинарный алгоритм
			 while (1 == 1)
          	{
	          mid = (st + fn) / 2;
	          res = str_ident((first+mid)->name,fstr);
	          if(res == 1)	
	          fn = mid - 1;
	          if(res == (-1))
	          st = mid + 1; 
	          if(res == 0)
			  {
	             resf = mid;
	             break;
	          }
	          if(st > fn)
	            {
	             resf = 0;
	             break;
	            }	 	  
	        }
			  if (resf == 0)
			  {
			  	fprintf(f3,"ERROR 203: unable to find  this func:\n");
			  	write_str(fstr,f3);
			  	fprintf(f3,"\n");
			  	goto crashed;
			  }	 
			  str_cl[coun_cl] = (first+resf)->design;
			  coun_cl += 1;		  
		   }   
        }
    }
    end_check:;
    str_cl[coun_cl] = 300;
     str_cl[++coun_cl] = '=';
     if(ins != 300)
     {
     	fprintf(f3,"ERROR 204: There are number of '(' not such as ')'!!!\n");
     	goto crashed;
	 }
     ins = 299;
     i = 1;
     tmp = '0';
 while(tmp != '=')
    {
    	tmp = str_cl[i];
    	if((tmp > 129) && (tmp < 160))
    	 {
    	 	i2 = str_cl[i] - 130;
    	 	fprintf(f3,"%f",nums[i2]);
		 }
		if((tmp > 189) && (tmp < 221))
		{
			tmp_3 = first + tmp - 189;
	    	write_str(tmp_3->name,f3);
		}
		if((tmp > 299) && (tmp < 350))
    	 {
    	 	if(ins < tmp)
    	 	{
    	 	   fprintf(f3,"(");
    	 	   ins++;
		    }else
			{
		    	if(ins == tmp)
    	 	{
    	 	   fprintf(f3,")");
    	 	   ins -= 1;
		    }  
        }
        }
        if(tmp < 130)
           fprintf(f3,"%c",tmp);
           i += 1;
    }
    fprintf(f3,"\n");
    int stat = 3;
    int res2,args, max = 150,res;
    coun_cl = 1;
    ins = 299;
    tmp = str_cl[coun_cl];
    while (tmp != '=')
	{
		res = what_is (tmp,ins);
		if(res == 4)
		{
			if((tmp == 204) || (tmp == 205))
			   args = 2;
			else
			args = 1;
			i = coun_cl;
	    	if(str_cl[i+1] != (ins + 1))
	    	{
	    		fprintf(f3, "\nERROR 206: func name must be finished with '('");
	    		goto crashed;
			}
			if(args == 2)
			{
	    		args = str_cl[++i];
	    		i += 1;
	    		while (str_cl[i] != args) i++;
				if(str_cl[i+1] != '_')
	    	{
	    		fprintf(f3,"\nERROR 207: Simbol '_' expected to be between func arguments");
	    		goto crashed;
			}
			 str_cl[i+1] = 500;
			 if(str_cl[i+2] != args)
	    	{
	    		fprintf(f3,"ERROR 208: Simbol '('  to be landed one position right '_', like this: 'func(arg1)_(arg2)'\n");
	    		goto crashed;
			}				  
		    }
	    }
		if(res == 1) ins += 1;
		if(max < ins) max = ins;
		if(res == 2) ins -= 1;
		stat = control (res,stat);
		if(stat == (-1))
		{
			fprintf(f3,"ERROR 209: Wrong value at %d position\n", coun_cl);
			goto crashed;
		}
		tmp = str_cl[++coun_cl];		
	}
	//Основной алгоритм, вычисление выражения
	for(i = max; i > 299; i--)
	{
		num = 1;
		tmp = str_cl[num];
		while(tmp != '=')
		{
			if(tmp == i)
			{
				sum = 0;
				i2 = num + 1;
				while((str_cl[i2] < 130) || (str_cl[i2] > 160))
				   i2++;
				remind =  str_cl[i2];    
				oper = str_cl[++num];
				first_p = num;
				if(oper > 129)
				  {
                    oper = '+';
                    num -= 1;
                  }
                count = 0;
                tmp1 = '+';
                goto lab1;
                while(1 == 1)
                {   
					oper = str_cl[++num];
					if(oper == i)
					{
					   	if(tmp1 == '+')
						  sum += count;
						if(tmp1 == '-')
						  sum -= count;
						goto label2; 
					}
					lab1:;
					if(str_cl[++num] == '-')
					  gain = -1;
					else
					  gain = 1; 
					  if(str_cl[num] < 129)
					  num++;
					  if(str_cl[num] == (i+1))
					  {
						 result = nums[str_cl[++num] - 130];
					  	 result *= gain;
					  	 while(str_cl[num] != (i+1))
						   num += 1;
					  }
					  else
					  	if((str_cl[num] > 189) && (str_cl[num] < 220))
					     {
					  	    int func_name = str_cl[num];
							tmp2 = str_cl[++num];
					  	    arg1 = nums[str_cl[++num] - 130];
					  	    while(str_cl[num] != tmp2) 
							    num++;
					  	    if((func_name == 204) || (func_name == 205))
					  	      {
									 num += 3;
					  	      	 arg2 = nums[str_cl[num] - 130];
					  	      	 while(str_cl[num] != tmp2) 
							        num++;	 
						      } 
						    result = call_f(func_name, arg1, arg2, toler, f3);
							if((result == ERR1) || (result == ERR2))
							    goto crashed;
					     }
					     else
                            if((str_cl[num] > 129) && (str_cl[num] < 160))
								result = nums[str_cl[num] - 130] * gain;
					if((oper == '+') || (oper == '-'))   
					{
						if(tmp1 == '+')
						  sum += count;
						if(tmp1 == '-')
						  sum -= count;  
						tmp1 = oper;
						count = result;
					}else
					{
					    if(oper == '*')	
					      count *= result;
					    if(oper == '/')	
					      count /= result;  
					}				 				     	
				}
				label2:;
				nums[remind - 130] = sum;
				str_cl[first_p] = remind;	   
			}
			tmp = str_cl[++num];
		}
	}
	remind = str_cl[2] - 130;
	fprintf(f3,"%f\n",nums[remind]);	
    crashed:;      
  }
  end:;
  fseek(f,-2, SEEK_END);  
  fprintf(f,"  ");
  fclose(f);
  fclose(f2);
  fclose(f3);
}
