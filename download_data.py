from datasets import load_dataset

ds = load_dataset("stas/oscar-en-10k")
with open("oscar_10k.txt", "w", encoding="utf-8") as f:
    for row in ds["train"]:
        f.write(row["text"].replace("\n", " ") + "\n")