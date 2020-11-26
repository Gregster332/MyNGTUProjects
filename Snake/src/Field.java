import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;


class GameField extends JPanel implements ActionListener{
    private final int SIZE = 400;
    private final int DOT = 16;
    private final int ALL_DOTS = 400;
    private Image snake;
    private Image apple;
    private Image cherry;
    private int appleX;
    private int appleY;
    private int cherryX;
    private int cherryY;
    private int[] x = new int[ALL_DOTS];
    private int[] y = new int[ALL_DOTS];
    private int dots;
    private Timer timer;
    private boolean left = false;
    private boolean right = true;
    private boolean up = false;
    private boolean down = false;
    private boolean inGame = true;
    private int randomChoice = (int) (Math.random() );


    public GameField(){
        setBackground(Color.orange);
        loadImages();
        initGame();
        addKeyListener(new FieldKeyListener());
        setFocusable(true);

    }

    public void initGame(){
        dots = 3;
        for (int i = 0; i < dots; i++) {
            x[i] = 48 - i*DOT;
            y[i] = 48;
        }
        timer = new Timer(250,this);
        timer.start();
//        if (dots % 2 == 0) {
//            createApple();
//        } else {
//            createCherry();
//        }
        createApple();
    }

    public void createApple(){
        appleX = new Random().nextInt(25)*DOT;
        appleY = new Random().nextInt(25)*DOT;
    }

    public void createCherry(){
        cherryX = new Random().nextInt(25)*DOT;
        cherryY = new Random().nextInt(25)*DOT;
    }

    public void loadImages(){
        ImageIcon iia = new ImageIcon("apple.png");
        apple = iia.getImage();
        ImageIcon iic = new ImageIcon("cherry.png");
        cherry = iic.getImage();
        ImageIcon iid = new ImageIcon("snake.png");
        snake = iid.getImage();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if(inGame){
            //if (randomChoice == 0) {
             //   g.drawImage(cherry, cherryX, cherryY, this);
           // } else {
                g.drawImage(apple, appleX, appleY, this);
           // }

            for (int i = 0; i < dots; i++) {
                g.drawImage(snake,x[i],y[i],this);
            }
        } else{
            String string = "Ты продул!!!";
            //Font font = new Font("Arial", 22, Font.BOLD);

            g.setColor(Color.black);
            setBackground(Color.white);
            //g.setFont(font);

            g.drawString(string,150,SIZE/2);
        }
    }

    public void move(){
        for (int i = dots; i > 0; i--) {
            x[i] = x[i-1];
            y[i] = y[i-1];
        }
        if(left){
            x[0] -= DOT;
        }
        if(right){
            x[0] += DOT;
        } if(up){
            y[0] -= DOT;
        } if(down){
            y[0] += DOT;
        }
    }

    public void checkApple(){
            if (x[0] == appleX && y[0] == appleY) {
                System.out.println(dots);
                dots++;
                createApple();

        }
    }

    public void checkCherry(){
        if (x[0] == cherryX && y[0] == cherryY) {
            System.out.println(dots);
            dots++;
            createCherry();

        }
    }

    public void checkCollisions(){
        for (int i = dots; i >0 ; i--) {
            if(i>4 && x[0] == x[i] && y[0] == y[i]){
                inGame = false;
            }
        }

        if(x[0]>SIZE){
            inGame = false;
        }
        if(x[0]<0){
            inGame = false;
        }
        if(y[0]>SIZE){
            inGame = false;
        }
        if(y[0]<0){
            inGame = false;
        }
    }

    //метод, в котором отслеживаются все действия игры
    @Override
    public void actionPerformed(ActionEvent e) {
        if(inGame){
            checkApple();
            checkCollisions();
            move();
        }
        repaint();
    }

    class FieldKeyListener extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e) {
            super.keyPressed(e);
            int key = e.getKeyCode();
            if(key == KeyEvent.VK_LEFT && !right){
                left = true;
                up = false;
                down = false;
            }
            if(key == KeyEvent.VK_RIGHT && !left){
                right = true;
                up = false;
                down = false;
            }

            if(key == KeyEvent.VK_UP && !down){
                right = false;
                up = true;
                left = false;
            }
            if(key == KeyEvent.VK_DOWN && !up){
                right = false;
                down = true;
                left = false;
            }
        }
    }


}
