/**
 * Class Candy extends from DesserItem
 * @author Ricky-Ting (1770048119@qq.com)
 */
public class Candy extends DessertItem {
	private String name;
	private double weight;
	private int price_per_pound;

/**
 * Initializes Candy data
 */   
	public Candy(String name,double weight, int price_per_pound) {
		if (name.length() <= DessertShoppe.MAX_ITEM_NAME_SIZE)
      		this.name = name;
   		else 
      		this.name = name.substring(0,DessertShoppe.MAX_ITEM_NAME_SIZE);
		this.weight=weight;
		this.price_per_pound=price_per_pound;
	}

/**
 * Calculate and Return the cost of Candy
 * @return cost of Candy
 */
	public int getCost() {
		return (int) Math.round(weight*price_per_pound);
		
	}

/**
 * Return some information of Candy
 * @return information of Candy
 */
	public java.lang.String toString() {
		String s="";
		s+=String.format("%.2f", weight);
		//s+=Double.toString(weight);
		s+=" lbs. @ ";
		s+=DessertShoppe.cents2dollarsAndCents(price_per_pound);
		s+=" /lb.\t \n";
		s+=String.format("%-25s%6s\n",name, DessertShoppe.cents2dollarsAndCents(this.getCost()));
		return s;
	}


}