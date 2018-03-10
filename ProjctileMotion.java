import java.util.Scanner;



public class ProjectileMotion {                                             // The purpose of this class is to describe the motion of a projectile according to Newtonian Physics

    public static void main(String[] args) {
        boolean repeat = true;
        Scanner Oscan = new Scanner(System.in);
        System.out.println("This program will tell facts about the motion of a projectile that is tossed");

        while (repeat) {


            System.out.println("Please enter an intial Velocity (in Meters per second)");
            double a = Oscan.nextDouble();
            System.out.println("Please Enter a launch angle(in degrees with horiziontal being 0 and vertical being 90");
            int b = Oscan.nextInt();

            System.out.println("");
            Ball alpha = new Ball(a, b);

            System.out.println("Time in the air:");

            System.out.println(alpha.findTime());

            System.out.println("Max Height of the projectile:");
            System.out.println(alpha.findMaxHeight());

            System.out.println("Max Height of the projectile:");
            System.out.println( alpha.findHorizontalDistance());

            System.out.println("Want to try again y/n");
            if (Oscan.next().charAt(0) == 'y')
                repeat = true;
            else
                repeat = false;
            System.out.println("");
            System.out.println("");
            System.out.println("");
        }

    }

    static class Ball {


        double Initial_Velocity;
        int Launch_Angle;
        double gravity = 9.8;
        double Time;
        double sine;


        public Ball( double Initial_Velocity, int Launch_Angle) {


            this.Initial_Velocity = Initial_Velocity;
            this.Launch_Angle = Launch_Angle;
            this.sine = Math.sin(Math.toRadians(Launch_Angle));



            //     double Max_Height =


        }

        public double findTime(){                   // need to bug fix.


            this.Time = (2*Initial_Velocity*sine)/gravity;
            int temp = (int) (Time * 100.00);
            Time =((double) temp) / 100.0;
            return this.Time;

        }

        public double findMaxHeight(){

            double high =  (Math.pow(this.Initial_Velocity,2)*Math.pow(this.sine,2)/2/gravity);
            int temp = (int) (high * 100.00);
            high =((double) temp) / 100.0;

            return  high;
        }
        public double findHorizontalDistance() {
            double dist = (Math.pow(this.Initial_Velocity,2) * Math.sin(Math.toRadians(2*Launch_Angle)))/gravity;
            int temp = (int) (dist * 100.00);
            dist =((double) temp) / 100.0;
            return dist;
        }

    }

}
