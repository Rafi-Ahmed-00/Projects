
import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class calculator implements ActionListener
{

	JFrame frame;
	JTextField text;
	JButton[] numButtons = new JButton[10];
	JButton[] funcButtons = new JButton[8];
	JButton add,subtract,multiply,divide,decimal,equal,delete,clear;
	JPanel panel;
	
	Font myFont = new Font("Helvetica", Font.BOLD,30);
	double num1 = 0, num2 = 0, result = 0;
	char operator;
	
	calculator()
	{
		frame = new JFrame("Calculator");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(420,550);
		frame.setLayout(null);
		
		text = new JTextField();
		text.setBounds(50, 25, 300, 50);
		text.setFont(myFont);
		text.setEditable(false);
		
		add = new JButton("+");
		subtract = new JButton("-");
		multiply = new JButton("*");
		divide = new JButton("/");
		decimal = new JButton(".");
		equal = new JButton("=");
		delete = new JButton("DELETE");
		clear = new JButton("CLEAR");
		
		funcButtons[0] = add;
		funcButtons[1] = subtract;
		funcButtons[2] = multiply;
		funcButtons[3] = divide;
		funcButtons[4] = decimal;
		funcButtons[5] = equal;
		funcButtons[6] = delete;
		funcButtons[7] = clear;
		
		for(int i = 0; i < 8; i++)
			{
				funcButtons[i].addActionListener(this);
				funcButtons[i].setFont(myFont);
				funcButtons[i].setFocusable(false);
			}
		
			for(int i = 0; i < 10; i++)
				{
					numButtons[i] = new JButton(String.valueOf(i));
					numButtons[i].addActionListener(this);
					numButtons[i].setFont(myFont);
					numButtons[i].setFocusable(false);
				}
		delete.setBounds(50, 430, 145, 50);
		clear.setBounds(205, 430, 145, 50);
	
		panel = new JPanel();
		panel.setBounds(50, 100, 300, 300);
		panel.setLayout(new GridLayout(4,4,10,10));
		
		
		panel.add(numButtons[1]);
		panel.add(numButtons[2]);
		panel.add(numButtons[3]);
		panel.add(add);
		
		panel.add(numButtons[4]);
		panel.add(numButtons[5]);
		panel.add(numButtons[6]);
		panel.add(subtract);
		
		panel.add(numButtons[7]);
		panel.add(numButtons[8]);
		panel.add(numButtons[9]);
		panel.add(multiply);
		panel.add(decimal);
		panel.add(numButtons[0]);
		panel.add(equal);
		panel.add(divide);
		
		frame.add(panel);
		frame.add(clear);
		frame.add(delete);
		frame.add(text);
		frame.setVisible(true);
	}
	

	public static void main(String[] args) 
	{
		calculator calc = new calculator();

	}


	@Override
	public void actionPerformed(ActionEvent e) 
	{
		for(int i = 0; i < 10; i++)
		{
			if(e.getSource() == numButtons[i])
			{
				text.setText(text.getText().concat(String.valueOf(i)));
			}
		}
		if(e.getSource() == decimal)
		{
			text.setText(text.getText().concat("."));
		}
		if(e.getSource() == add)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '+';
			text.setText("");
		}
		if(e.getSource() == subtract)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '-';
			text.setText("");
		}
		if(e.getSource() == multiply)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '*';
			text.setText("");
		} 
		if(e.getSource() == divide)
		{
			num1 = Double.parseDouble(text.getText());
			operator = '/';
			text.setText("");
		}
		if(e.getSource() == equal)
		{
			num2 = Double.parseDouble(text.getText());
			
			switch(operator)
				{
				case'+':
					result = num1 + num2;
					break;
				case'-':
					result = num1 - num2;
					break;
				case'*':
					result = num1 * num2;
					break;
				case'/':
					result = num1 / num2;
					break;
				}
			text.setText(String.valueOf(result));
			num1 = result;
		}
		if(e.getSource() == clear)
		{
			text.setText("");
		} 
		if(e.getSource() == delete)
		{
			String string = text.getText();
			text.setText("");
			for(int i = 0; i < string.length() - 1; i++)
				{
					text.setText(text.getText() + string.charAt(i));
				}
		} 
	}

}
