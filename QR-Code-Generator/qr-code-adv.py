import qrcode

from PIL import Image

qr=qrcode.QRCode(version=1,
                 error_correction=qrcode.constants.ERROR_CORRECT_H,
                 box_size=10,
                 border=5,)

#LINK
qr.add_data("https://www.linkedin.com/in/nsr2k25/")

qr.make(fit=True)

img=qr.make_image(fill_color="#004d40",
                  back_color="#f5f5dc")

img.save("qr_generated.png")