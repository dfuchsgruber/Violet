
const input = document.getElementById("pokemon-search");
const cards = Array.from(document.querySelectorAll(".pokemon-card"));
if (input) {
  input.addEventListener("input", () => {
    const query = input.value.trim().toLowerCase();
    for (const card of cards) {
      card.hidden = query && !card.dataset.search.includes(query);
    }
  });
}
