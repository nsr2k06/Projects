# Project Report — Entropy-based Password Advisor

## Project Title
Entropy-based Password Advisor (C++)

## Objective
Measure password strength using entropy, detect common passwords, and provide actionable suggestions to improve password security.

## Methodology
- Determine character pool size based on classes used (lowercase, uppercase, digits, special).
- Estimate entropy using: bits = length * log2(poolSize).
- Rate passwords using entropy thresholds.
- Check password against a small list of common passwords.
- Provide suggestions to improve entropy.

## Testing (examples)
1) Input: "12345"
- Entropy: low → Rating: Very Weak
- Breach check: Found in common list
- Suggestions: Increase length, add letters and symbols

2) Input: "Abc123!"
- Entropy: moderate → Rating: Weak/Moderate
- Suggestions: Increase length, add more varied chars

3) Input: "G7t!p9Kx3L#"
- Entropy: high → Rating: Strong
- Suggestions: Keep length and variety

## Conclusion
A compact tool to teach password security basics and provide immediate suggestions. Can be extended by connecting to large breached-password databases, adding GUI, or making a web version.

## Future Work
- Integrate with a real breached-password API or a larger dataset.
- Build a small GUI (Qt or web).
- Add user configuration (desired strength, policy).
