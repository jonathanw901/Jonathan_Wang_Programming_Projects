from flask import Flask
import pandas

app = Flask(__name__)

@app.route('/most_popular')
def showTags():
    items = pandas.read_csv(
'C:\\Users\\jonat\\Documents\\Programming\\2020 Coding Lessons\\5-8-2020 Project\\Chart1.csv')
    # Pick my right CSV file for above.
    return items.to_html()

@app.route('/by_category')
def showTags2():
    items = pandas.read_csv(
'C:\\Users\\jonat\\Documents\\Programming\\2020 Coding Lessons\\5-8-2020 Project\\Chart2.csv')
    # Pick my right CSV file for above.
    return items.to_html()

if __name__ == '__main__':
    app.run()
