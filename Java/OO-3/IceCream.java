/**
 * Class IceCream extends from DesserItem
 * @author Ricky-Ting (1770048119@qq.com)
 */
public class IceCream extends DessertItem {
	private String name;
	private int price;

/**
 * Null constructor for DessertItem class (must be contained otherwise the Sundae won't work properly)
 */
	public IceCream() {
	}
/**
 * Initializes IceCream data
 */   
	public IceCream(String name,int price) {
		if (name.length() <= DessertShoppe.MAX_ITEM_NAME_SIZE)
     		this.name = name;
   		else 
    		this.name = name.substring(0,DessertShoppe.MAX_ITEM_NAME_SIZE);
		this.price=price;
	}

/**
 * Calculate and Return the cost of IceCream
 * @return cost of IceCream
 */
	public int getCost() {
		return price;
	}
/**
 * Return some information of IceCream
 * @return information of IceCream
 */
	public java.lang.String toString() {
		String s="";
		s+=String.format("%-25s%6s\n",name, DessertShoppe.cents2dollarsAndCents(this.getCost()));
		return s;
	}
}