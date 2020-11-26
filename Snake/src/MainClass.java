import javax.swing.*;

public class MainClass extends JFrame {

    public MainClass(){
        setTitle("snakeGame");
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(400, 425);
        setLocation(400, 400);
        add(new GameField());
        setVisible(true);
    }

    public static void main(String[] args){
        MainClass main = new MainClass();

    }

}
