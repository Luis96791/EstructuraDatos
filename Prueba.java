/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.Scanner;
/**
 *
 * @author Luis
 */

public class Prueba {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int opc = 0;
        String users[] = new String[5];
        boolean existe = false;
        
        do {
            System.out.println("1-. Login");
            System.out.println("2-. Register");
            System.out.println("3-. Imprimir");
            System.out.print("Ingrese una Opcion: ");
            opc = sc.nextInt();
            
            switch(opc)
            {
                case 1:
                    System.out.println("--Login--");
                    System.out.print("Su username: ");
                    String us = sc.next();
                    for (int i = 0; i < users.length; i++) {
                        if(us.equals(users[i]))
                        {
                            System.out.println("Username encontrado :)");
                            existe = true;
                            break;
                        }
                    }
                    if(!existe)
                    {
                        System.out.println("Username no se encontro en el arreglo :(");
                    }
                    break;
                case 2:
                    System.out.println("--Register--");
                    System.out.print("username: ");
                    String s = sc.next();
                    for (int i = 0; i < users.length; i++) {
                        if(users[i] != null)
                        {
                            if(users[i].equals(s))
                            {
                                System.out.println("Este usuario ya existe...");
                                existe = true;
                                break;
                            }
                        }
                    }
                    if(!existe)
                    {
                        for (int j = 0; j < users.length; j++) {
                            if(users[j] == null)
                            {
                                users[j] = s;
                                break;
                            }
                        }
                    }
                    break;
                case 3:
                    System.out.println("--Imprimir--");
                    int temp = 0;
                    while(temp < users.length)
                    {
                        if(users[temp] != null)
                        {
                            System.out.println("Usuario: "+users[temp]);
                        }
                        temp++;
                    }
                    break;
                    
            }
            existe = false;
        } while (opc != -1);
        
    }
   
}
