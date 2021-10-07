# Changing Whatsapp profile by live comera using Selenium
import pandas as pd
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import UnexpectedAlertPresentException
from selenium.common.exceptions import NoAlertPresentException
import keyboard
import time

driver = webdriver.Chrome(r'C:\Selenium\chromedriver.exe')
driver.maximize_window()
driver.get("https://web.whatsapp.com/")
driver.implicitly_wait(30)
elem = driver.find_element_by_xpath("//*[@id='side']/header/div[1]/div/div/span").click()
driver.implicitly_wait(5)
time.sleep(2)
elem = driver.find_element_by_xpath("//*[@id='app']/div/div/div[2]/div[1]/span/div/div/div/div[1]/div/div/span/div").click()
time.sleep(2)
keyboard.press_and_release('down,enter')
driver.implicitly_wait(12)
time.sleep(3)
keyboard.press_and_release('tab,tab,enter')
time.sleep(2)
elem = driver.find_element_by_xpath("//*[@id='app']/div/span[2]/div/span/div/div/div/div/div/div/div/div[2]/span/div/div/span").click()
time.sleep(2)
elem = driver.find_element_by_xpath("//*[@id='app']/div/span[2]/div/span/div/div/div/div/div/div/div/div[2]/span/div/div/span").click()


