//
//  ContentView.swift
//  TipCalculator
//
//  Created by Jonathan Wang on 5/29/23.
//

import SwiftUI

struct ContentView: View {
    
    @State private var billAmount: String = ""
    @State private var taxAmount: String = ""
    @State private var totalCost: String = ""
    @State private var taxRate: Double = 0.0
    @State private var tipResults: String = "0.0"
    @State private var isEditing = false
    @State var tip15 = true
    @State var tip20 = true
    @State var tip25 = true
    
    //create an instance of a tipCalculator object
    var objTipCalculator = tipCalculator(total: 0.0, taxPct: 0.0)
    
    //set possible tip percentages
    @State var tipPercentages: [Double] = []

    var body: some View {
        VStack {
                
            Text("Welcome to my Tip Calculator")
                .font(.headline)
                .padding(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/)
                .foregroundColor(/*@START_MENU_TOKEN@*/.purple/*@END_MENU_TOKEN@*/)
            
            HStack {
                Text("Enter total bill including tax:")
                    .padding(.leading)
                
                TextField("Enter amount", text: $billAmount)
                    .padding(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/)
                    .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: /*@START_MENU_TOKEN@*/1/*@END_MENU_TOKEN@*/)
                    .scaledToFit()
                
            }
            
            Text("Set tax rate below:")
                .padding(/*@START_MENU_TOKEN@*/[.top, .leading, .trailing]/*@END_MENU_TOKEN@*/)
            
            HStack{
                
                Slider(value: $taxRate,
                    in: 0...20,
                    onEditingChanged: { editing in
                        isEditing = editing })
                    .padding(/*@START_MENU_TOKEN@*/[.leading, .bottom, .trailing]/*@END_MENU_TOKEN@*/)
                
                Text("\(round(taxRate))"+"%")
                    .foregroundColor(isEditing ? .red : .blue)
                    .padding(.all)
            }
            
            HStack{
                Toggle("15%->", isOn: $tip15)
                Toggle("20%->", isOn: $tip20)
                Toggle("25%->", isOn: $tip25)
            }
            
            
            
            Button("Calculate Tip Options!", action: {
                
                //set the tipCalculator's percentage based on the value of the tax slider
                objTipCalculator.taxPct = taxRate / 100.0
                
                //set tipCalculator's total from the billAmount textfield
                if let totalBillAmount = Double(billAmount) {
                    
                    //accept only numeric values greater than or equal to zero
                    if totalBillAmount >= 0 {
                        
                        //set the TipCalculator's total bill amount
                        objTipCalculator.total = totalBillAmount
                        
                        if tip15 == true{
                            let _ = tipPercentages.append(0.15)
                        } else {
                            
                            let _ = tipPercentages.removeAll { value in
                                return value == 0.15
                            }
                        }
                        
                        if tip20 == true{
                            let _ = tipPercentages.append(0.20)
                        } else {
                            
                            let _ = tipPercentages.removeAll { value in
                                return value == 0.20
                            }
                        }
                        
                        if tip25 == true{
                            let _ = tipPercentages.append(0.25)
                        } else {
                            
                            let _ = tipPercentages.removeAll { value in
                                return value == 0.25
                            }
                        }
                        
                        //ask the objTipCalculator object to calculate all possible tips based on the tipPercentages
                        let possibleTips = objTipCalculator.calcPossibleTips(tipPercentages: tipPercentages)
                        
                        //prepare a results string for output by traversing the possibleTips dictionary
                        var results = ""
                        for (tipPct, tipValue) in possibleTips {
                            results += "A \(tipPct)% tip would be $\(tipValue)\n"
                        }
                        tipResults = "After excluding taxes, your tip options are:\n" + results
                    } else { tipResults = "Enter a numeric value greater than zero for total bill amount."}
                    
                } else {
                    tipResults = "Enter only numeric values for total bill amount."
                    print("Console Message: Invalid input value for total bill amount.")
                }
                let costb4tax = objTipCalculator.calcNoTax()
                billAmount = "Cost without tax is $" + String(costb4tax)
                let tax = objTipCalculator.calctaxAmt()
                taxAmount = "Tax is $" + String(tax)
                let tot = objTipCalculator.calcTotal()
                totalCost = "Total cost without tip is $" + String(tot)
                
            })
            .padding(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/)
            .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: /*@START_MENU_TOKEN@*/1/*@END_MENU_TOKEN@*/)
            .accentColor(/*@START_MENU_TOKEN@*/.white/*@END_MENU_TOKEN@*/)
            .background(/*@START_MENU_TOKEN@*//*@PLACEHOLDER=View@*/Color.blue/*@END_MENU_TOKEN@*/)
            
            VStack {
                Text(billAmount)
                Text(taxAmount)
                Text(totalCost)
            }
            
            Text(tipResults)
                .multilineTextAlignment(.leading)
                .lineLimit(/*@START_MENU_TOKEN@*/10/*@END_MENU_TOKEN@*/)
                .padding(/*@START_MENU_TOKEN@*/.all/*@END_MENU_TOKEN@*/)
                .frame(width: /*@START_MENU_TOKEN@*/300.0/*@END_MENU_TOKEN@*/, height: /*@START_MENU_TOKEN@*/200.0/*@END_MENU_TOKEN@*/)
                
            Button("Clear All", action: {
                billAmount = ""
                tipResults = ""
                taxRate = 0.0
            })
            .padding(.all)
            .border(/*@START_MENU_TOKEN@*/Color.black/*@END_MENU_TOKEN@*/, width: /*@START_MENU_TOKEN@*/1/*@END_MENU_TOKEN@*/)
            .background(/*@START_MENU_TOKEN@*//*@PLACEHOLDER=View@*/Color.blue/*@END_MENU_TOKEN@*/)
            .accentColor(/*@START_MENU_TOKEN@*/.white/*@END_MENU_TOKEN@*/)
            Spacer()
        }
    }

}



struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
        
    }
}
