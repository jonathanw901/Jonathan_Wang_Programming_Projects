from bs4 import BeautifulSoup
import requests
import pandas

rank_list = []
tag_list = []
numPosts_list = []

def parse():
    soup = BeautifulSoup(page.content, 'html.parser')
    ranks = soup.find_all('div', {'class': "i-num"})
    tags = soup.find_all('div', {'class': "i-tag"})
    numPosts = soup.find_all('div', {'class': "i-total"})
    for i in range (0,100):
        #print(ranks[i].get_text())
        #print(tags[i].get_text())
        #print(numPosts[i].get_text())                          
        rank_list.append(ranks[i].get_text())
        tag_list.append(tags[i].get_text())
        numPosts_list.append(numPosts[i].get_text())

page = requests.get("https://top-hashtags.com/instagram/")
parse()

counter = 101
while (counter < 10000):
    page = requests.get("https://top-hashtags.com/instagram/" + str(counter) + "/")
    parse()
    counter = counter + 100

extractedData=pandas.DataFrame({
"Rank": rank_list,
"Instagram Hashtag": tag_list,
"Number of Posts": numPosts_list
})
extractedData.to_csv('Chart1.csv')

items_list = []

page = requests.get("https://www.hashtagsforlikes.co/popular-instagram-hashtags")
soup = BeautifulSoup(page.content, 'html.parser')

cat = soup.find('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
subCat = soup.find('h3', {'class': "acc_container_category"})
subCat2 = subCat.text
subCat2 = subCat2.replace(':','')
subCat2 = subCat2.replace('\n','')
tags = soup.find('span', {'class': "mt-2"})
tags2 = tags.text
tags2 = tags2.replace(' ','')
tags2 = tags2.replace('\n','')
#print("Sub-Category: " + subCat2)
#print(tags2)
items_list.append("Sub-Category: " + subCat2)
items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,2):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,7):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,12):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,12):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,4):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,5):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,4):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,4):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
subCat = subCat.findNext('h3', {'class': "acc_container_category"})
tags = tags.findNext('span', {'class': "mt-2"})
for i in range (0,6):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,8):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,6):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,3):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,4):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,8):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,3):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

cat = cat.findNext('h2', {'class': "acc_title_bar"})
#print("Category: " + cat.find('a').get_text())
items_list.append("Category: " + cat.find('a').get_text())
for i in range (0,10):
    subCat = subCat.findNext('h3', {'class': "acc_container_category"})
    subCat2 = subCat.text
    subCat2 = subCat2.replace(':','')
    subCat2 = subCat2.replace('\n','')
    tags = tags.findNext('span', {'class': "mt-2"})
    tags2 = tags.text
    tags2 = tags2.replace(' ','')
    tags2 = tags2.replace('\n','')
    #print("Sub-Category: " + subCat2)
    #print(tags2)
    items_list.append("Sub-Category: " + subCat2)
    items_list.append(tags2)

extractedData=pandas.DataFrame({
"Instagram Hashtags by Category": items_list
})
extractedData.to_csv('Chart2.csv')




