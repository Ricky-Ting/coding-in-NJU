/**
 * Class Sundae extends from IceCream
 * @author Ricky-Ting (1770048119@qq.com)
 */
public class Sundae extends IceCream {
	private String name;
	private String topping_name;
	private int price;
	private int topping_price;
/**
 * Initializes Sundae data
 */   
	public Sundae(String name, int price, String topping_name, int topping_price) {
		if (name.length() <= DessertShoppe.MAX_ITEM_NAME_SIZE)
     		this.name = name;
   		else 
    		this.name = name.substring(0,DessertShoppe.MAX_ITEM_NAME_SIZE);
		this.price=price;
		this.topping_name=topping_name;
		this.topping_price=topping_price;
	}

/**
 * Calculate and Return the cost of Sundae
 * @return cost of Sundae
 */
	public int getCost() {
		return price+topping_price;
	}
/**
 * Return some information of Sundae
 * @return information of Sundae
 */
	public java.lang.String toString() {
		String s="";
		s+=String.format("%-25s%6s\n",name, DessertShoppe.cents2dollarsAndCents(this.getCost()));
		return s;
	}
}