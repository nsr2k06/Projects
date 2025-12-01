import streamlit as st

st.set_page_config(page_title="BMI Calculator", layout="wide")
st.title("BMI Calculator")

# USER INPUT
height_cm = st.slider("Enter Your Height (cm):", 100, 250, 175)
weight_kg = st.slider("Enter Your Weight (kg):", 30, 200, 75)

# CONVERT TO METERS & CALCULATE BMI
height_m = height_cm / 100.0
bmi = weight_kg / (height_m ** 2)

# SHOW BMI (metric)
st.metric("Your BMI", f"{bmi:.2f}")

# CATEGORY
if bmi < 18.5:
    category = "Underweight"
    st.info("Category: Underweight — BMI less than 18.5")
elif 18.5 <= bmi < 25:
    category = "Normal weight"
    st.success("Category: Normal weight — BMI between 18.5 and 24.9")
elif 25 <= bmi < 30:
    category = "Overweight"
    st.warning("Category: Overweight — BMI between 25 and 29.9")
else:
    category = "Obesity"
    st.error("Category: Obesity — BMI 30 or above")

# Extra info
st.write("### BMI Categories")
st.write("- Underweight: BMI less than 18.5")
st.write("- Normal Weight: BMI between 18.5 and 24.9")
st.write("- Overweight: BMI between 25 and 29.9")
st.write("- Obesity: BMI 30 or above")

#python -m streamlit run "C:\Users\visha\OneDrive\Desktop\My Projects\BMI Calculator\app.py"
