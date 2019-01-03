import java.util.*;

/**
 * Class Checkout 
 * @author Ricky-Ting (1770048119@qq.com)
 */
public class Checkout {
	private Vector<DessertItem> Items;

/*
 * Creates a Checkout instance with an empty list of DessertItem's
 */
	public Checkout() {
		Items=new Vector<DessertItem>();
	}

/*
 * Returns the number of DessertItem's in the list
 * @return number of DessertItem's in the list
 */
	public int numberOfItems() {
		return this.Items.size();
	}

/*
 * A DessertItem is added to the end of the list of items
 * @para item - DessertItem to add to list of items
 */
	public void enterItem(DessertItem item) {
		this.Items.add(item);
	}

/*
 * Clears the Checkout to begin checking out a new set of items
 */
	public void clear() {
		this.Items.removeAllElements();
	}

/*
 * Returns total cost of items in cents (without tax)
 * @return total cost of items in cents (without tax)
 */
	public int totalCost() {
		int totalcost=0;
		Iterator<DessertItem> it= Items.iterator();
		while(it.hasNext())	{
			DessertItem someitem = (DessertItem) it.next();
			totalcost+=someitem.getCost();
		}
		return totalcost;
	}

/*
 * Returns total tax on items in cents
 * @return total tax on items in cents
 */
	public int totalTax() {
		int totaltax=0;
		Iterator<DessertItem> it= Items.iterator();
		while(it.hasNext())	{
			DessertItem someitem = (DessertItem) it.next();
			totaltax+= (int) Math.round((someitem.getCost()*DessertShoppe.TAX_RATE)/100);
		}
		return totaltax;
	}

/*
 * Returns a String representing a receipt for the current list of items
 * @overrides toString in class java.lang.Object
 * @return a String representing a receipt for the current list of DessertItem's with the name of the Dessert store, the items purchased, the tax, and the total cost, for example,
 */
	public java.lang.String toString() {
		String s="";
		s+="     ";
		s+=DessertShoppe.STORE_NAME;
		s+="\n";
		s+="     --------------------";
		s+="\n";
		s+="\n";
		Iterator<DessertItem> it= Items.iterator();
		while(it.hasNext())	{
			DessertItem someitem = (DessertItem) it.next();
			if(someitem.getClass()==Candy.class) {
				Candy tmp=(Candy) someitem;
				s+=tmp.toString();
				
			}
			if(someitem.getClass()==Cookie.class) {
				Cookie tmp=(Cookie) someitem;
				s+=tmp.toString();
			}
			if(someitem.getClass()==IceCream.class) {
				IceCream tmp=(IceCream) someitem;
				s+=tmp.toString();
			}
			if(someitem.getClass()==Sundae.class) {
				Sundae tmp=(Sundae) someitem;
				s+=tmp.toString();
			}
		}
		s+="\n";	
		s+=String.format("%-25s%6s\n","Tax", DessertShoppe.cents2dollarsAndCents(this.totalTax()));
		s+=String.format("%-25s%6s\n","Total Cost", DessertShoppe.cents2dollarsAndCents(this.totalTax() + this.totalCost()));


		return s;
	}


}