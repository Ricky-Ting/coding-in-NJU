/**
 * Class Cookie extends from DesserItem
 * @author Ricky-Ting (1770048119@qq.com)
 */
public class Cookie extends DessertItem {
	private String name;
	private int number;
	private int price_per_dozen;


/**
 * Initializes Cookie data
 */   
	public Cookie(String name,int number, int price_per_dozen) {
		if (name.length() <= DessertShoppe.MAX_ITEM_NAME_SIZE)
     		this.name = name;
   		else 
    		this.name = name.substring(0,DessertShoppe.MAX_ITEM_NAME_SIZE);
		this.number=number;
		this.price_per_dozen=price_per_dozen;
	}
/**
 * Calculate and Return the cost of Cookie
 * @return cost of Cookie
 */
	public int getCost() {
		return (int) Math.round((double)(number*price_per_dozen)/12);
		
	}

/**
 * Return some information of Cookie
 * @return information of Cookie
 */
	public java.lang.String toString() {
		String s="";
		s+=Integer.toString(number);
		s+=" @ ";
		s+=DessertShoppe.cents2dollarsAndCents(price_per_dozen);
		s+=" /dz\t \n";
		s+=String.format("%-25s%6s\n",name, DessertShoppe.cents2dollarsAndCents(this.getCost()));
		return s;
	}

}